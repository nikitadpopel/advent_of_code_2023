#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <regex>

#include "Day6.h"
#include "../helpers/Reader.h"


Day6::Day6()
{
	m_vecInput = ReadInput("../../inputs/day6.input");
	std::string times = m_vecInput[0].substr(m_vecInput[0].find(":") + 1, -1);
	std::string dists = m_vecInput[1].substr(m_vecInput[1].find(":") + 1, -1);
	times = times.substr(times.find_first_not_of(" "), -1);
	dists = dists.substr(dists.find_first_not_of(" "), -1);
	std::string bigtime = times;
	std::string bigdist = dists;

	dists = dists.substr(dists.find_first_not_of(" "), -1);
	while (!times.empty())
	{
		if (times.find(" ") != std::string::npos)
		{
			m_times.push_back(stoi(times.substr(0, times.find(" "))));
			times = times.substr(times.find(" "), -1);
			times = times.substr(times.find_first_not_of(" "), -1);
		}
		else
		{
			m_times.push_back(stoi(times));
			times = "";
		}
	}
	while (!dists.empty())
	{

		if (dists.find(" ") != std::string::npos)
		{
			m_dists.push_back(stoi(dists.substr(0, dists.find(" "))));
			dists = dists.substr(dists.find(" "), -1);
			dists = dists.substr(dists.find_first_not_of(" "), -1);
		}
		else
		{
			m_dists.push_back(stoi(dists));
			dists = "";
		}
	}

	bigtime.erase(std::remove(bigtime.begin(), bigtime.end(), ' '), bigtime.end());
	bigdist.erase(std::remove(bigdist.begin(), bigdist.end(), ' '), bigdist.end());

	m_bigtime = stod(bigtime);
	m_bigdist = stod(bigdist);

}


double Day6::Part1()
{
	int racecount = m_times.size();
	int amountofwaystowin = 1;
	for (int i = 0; i < racecount; i++)
	{
		std::vector<int> distances;
		for (int j = 0; j <= m_times[i]; j++)
		{
			distances.push_back(j * (m_times[i] - j));
		}
		int wincount = 0;
		for (auto& round : distances)
		{
			if (round > m_dists[i])
			{
				wincount++;
			}
		}
		amountofwaystowin *= wincount;
	}
	return amountofwaystowin;
}

double Day6::Part2()
{
	double amountofwaystowin = 1;
	std::vector<double> distances;
	for (int j = 0; j <= m_bigtime; j++)
	{
		distances.push_back(j * (m_bigtime - j));
	}
	double wincount = 0;
	for (auto& round : distances)
	{
		if (round > m_bigdist)
		{
			wincount++;
		}
	}
	amountofwaystowin *= wincount;
	return amountofwaystowin;
}

bool Day6::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}