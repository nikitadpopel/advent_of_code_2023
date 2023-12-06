#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <regex>

#include "Day5.h"
#include "../helpers/Reader.h"


Day5::Day5()
{
	m_vecInput = ReadInput("../../inputs/day5.input");
	
}

enum readstate
{
	seed = 0,
	soil = 1,
	fert = 2,
	water = 3,
	light = 4,
	temp = 5,
	humid = 6,
	loc = 7
};

int Day5::Part1()
{

	std::vector<std::string>::iterator iter;
	int sum = 0;
	readstate currstate = readstate::seed;
	for (iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++)
	{
		if (!iter->empty())
		{
			std::string currstr = *iter;
			if (iter->find("seeds:") != std::string::npos)
			{
				currstr = currstr.substr(7, -1);
				while (!currstr.empty())
				{
					if (currstr.find(" ") != std::string::npos)
					{
						m_seeds.push_back(stoi(currstr.substr(0, currstr.find(" "))));
						currstr = currstr.substr(currstr.find(" ") + 1, -1);
					}
					else
					{
						m_seeds.push_back(stoi(currstr));
						currstr = "";
					}
				}
			}
			if (iter->find(":") != std::string::npos)
			{
				if (iter->find("seed-to-soil map") != std::string::npos)
				{
					currstate = readstate::soil;
				}
				if (iter->find("soil-to-fertilizer map") != std::string::npos)
				{
					currstate = readstate::fert;
				}
				if (iter->find("fertilizer-to-water map") != std::string::npos)
				{
					currstate = readstate::water;
				}
				if (iter->find("water-to-light map") != std::string::npos)
				{
					currstate = readstate::light;
				}
				if (iter->find("light-to-temperature map") != std::string::npos)
				{
					currstate = readstate::temp;
				}
				if (iter->find("temperature-to-humidity map") != std::string::npos)
				{
					currstate = readstate::humid;
				}
				if (iter->find("humidity-to-location map") != std::string::npos)
				{
					currstate = readstate::loc;
				}
			}
			else
			{
				mapping currmapreading;
				currmapreading.deststart = stoi(currstr.substr(0, currstr.find(" ")));
				currstr = currstr.substr(currstr.find(" ") + 1, -1);
				currmapreading.sourcestart = stoi(currstr.substr(0, currstr.find(" ")));
				currstr = currstr.substr(currstr.find(" ") + 1, -1);
				currmapreading.rangelen = stoi(currstr);
				switch (currstate)
				{
				case readstate::soil:
					m_soilmaps.push_back(currmapreading);
					break;
				case readstate::fert:
					m_fertmaps.push_back(currmapreading);
					break;
				case readstate::water:
					m_watermaps.push_back(currmapreading);
					break;
				case readstate::light:
					m_lightmaps.push_back(currmapreading);
					break;
				case readstate::temp:
					m_tempmaps.push_back(currmapreading);
					break;
				case readstate::humid:
					m_humidmaps.push_back(currmapreading);
					break;
				case readstate::loc:
					m_locmaps.push_back(currmapreading);
					break;
				default:
					break;
				}
			}
		}
	}
	return 0;
}

int Day5::Part2()
{
	return 0;
}

bool Day5::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}