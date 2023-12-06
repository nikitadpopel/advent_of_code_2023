#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <regex>

#include "Day5.h"
#include "../helpers/Reader.h"

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

Day5::Day5()
{
	m_vecInput = ReadInput("../../inputs/day5.input");

	std::vector<std::string>::iterator iter;
	double sum = 0;
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
						m_seeds.push_back(stod(currstr.substr(0, currstr.find(" "))));
						currstr = currstr.substr(currstr.find(" ") + 1, -1);
					}
					else
					{
						m_seeds.push_back(stod(currstr));
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
				currmapreading.deststart = stod(currstr.substr(0, currstr.find(" ")));
				currstr = currstr.substr(currstr.find(" ") + 1, -1);
				currmapreading.sourcestart = stod(currstr.substr(0, currstr.find(" ")));
				currstr = currstr.substr(currstr.find(" ") + 1, -1);
				currmapreading.rangelen = stod(currstr);
				currmapreading.sourceend = currmapreading.sourcestart + currmapreading.rangelen - 1;
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
}


double Day5::Part1()
{
	std::vector<double> seedsfinalnums;
	for (auto& seed : m_seeds)
	{
		double curr = seed;
		for (auto& soilmap : m_soilmaps)
		{
			if (curr >= soilmap.sourcestart && curr <= soilmap.sourceend)
			{
				double diff = soilmap.deststart - soilmap.sourcestart;
				curr = curr + diff;
				break;
			}
		}
		for (auto& fertmap : m_fertmaps)
		{
			if (curr >= fertmap.sourcestart && curr <= fertmap.sourceend)
			{
				double diff = fertmap.deststart - fertmap.sourcestart;
				curr = curr + diff;
				break;
			}
		}
		for (auto& watermap : m_watermaps)
		{
			if (curr >= watermap.sourcestart && curr <= watermap.sourceend)
			{
				double diff = watermap.deststart - watermap.sourcestart;
				curr = curr + diff;
				break;
			}
		}
		for (auto& lightmap : m_lightmaps)
		{
			if (curr >= lightmap.sourcestart && curr <= lightmap.sourceend)
			{
				double diff = lightmap.deststart - lightmap.sourcestart;
				curr = curr + diff;
				break;
			}
		}
		for (auto& tempmap : m_tempmaps)
		{
			if (curr >= tempmap.sourcestart && curr <= tempmap.sourceend)
			{
				double diff = tempmap.deststart - tempmap.sourcestart;
				curr = curr + diff;
				break;
			}
		}
		for (auto& humidmap : m_humidmaps)
		{
			if (curr >= humidmap.sourcestart && curr <= humidmap.sourceend)
			{
				double diff = humidmap.deststart - humidmap.sourcestart;
				curr = curr + diff;
				break;
			}
		}
		for (auto& locmap : m_locmaps)
		{
			if (curr >= locmap.sourcestart && curr <= locmap.sourceend)
			{
				double diff = locmap.deststart - locmap.sourcestart;
				curr = curr + diff;
				break;
			}
		}
		seedsfinalnums.push_back(curr);
	}
	double mymin = seedsfinalnums[0];
	for (auto& seed : seedsfinalnums)
	{
		if (seed < mymin)
		{
			mymin = seed;
		}
	}
	return 0;
}

double Day5::Part2()
{
	struct range {
		double start;
		double end;
	};
	bool readingstart = true;
	range currrange;
	double currstart = 0;
	std::vector<range> ranges;
	for (auto& seed : m_seeds)
	{
		if (readingstart)
		{
			currstart = seed;
			readingstart = false;
		}
		else
		{
			range currrange;
			currrange.start = currstart;
			currrange.end = currstart + seed - 1;
			ranges.push_back(currrange);
			readingstart = true;
		}
	}
	
	return 0;
}

bool Day5::Solve()
{
	//std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}