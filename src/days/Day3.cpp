#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>

#include "Day3.h"
#include "../helpers/Reader.h"

std::vector<Day3::coord> Day3::GetAdj(Day3::coord search)
{
	std::vector<Day3::coord> ret;
	
	if (search.col != 0 && search.row != 0) { ret.push_back({search.row - 1, search.col - 1 }); }
	if (search.row != 0) { ret.push_back({search.row - 1, search.col }); }
	if (search.col != m_vecInput[0].size() - 1  && search.row != 0) { ret.push_back({ search.row - 1,search.col + 1 }); }
	if (search.col != 0) { ret.push_back({search.row, search.col - 1 }); }
	if (search.col != m_vecInput[0].size() - 1) { ret.push_back({search.row,  search.col + 1 }); }
	if (search.col != 0 && search.row != m_vecInput.size() - 1) { ret.push_back({search.row + 1, search.col - 1 }); }
	if (search.row != m_vecInput.size() - 1) { ret.push_back({search.row + 1,  search.col}); }
	if (search.col != m_vecInput[0].size() - 1 && search.row != m_vecInput.size() - 1) { ret.push_back({ search.row + 1, search.col + 1 }); }
	return ret;
}

Day3::Day3()
{
	m_vecInput = ReadInput("inputs/day3.input");
	std::vector<std::string>::iterator iter;

	int row = 0;
	for(iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++ )
	{
		if(!iter->empty())
		{
			std::string str = *iter;
			std::vector<std::string>::iterator iter;
			int col = 0;
			struct part currpart;
			std::string valread = "";
			for(char& c : str) 
			{
				int val = c - '0';
				if (val > -1 && val < 10)
				{
					currpart.positions.push_back({row, col});
					valread += c;
				}
				else
				{
					if(!valread.empty())
					{
						currpart.value = stoi(valread);
						valread = "";
						m_parts.push_back(currpart);
						currpart = part();
					}
					if (!isblank(c) && c != '.')
					{
						m_sym.push_back({ row, col });
						if (c == '*')
						{
							m_gears.push_back({ row, col });
						}
					}
				}
				col++;
			}
			if(!valread.empty())
			{
					currpart.value = stoi(valread);
					valread = "";
					m_parts.push_back(currpart);
			}

		}
		row++;
	}
}

int Day3::Part1()
{
	int sum = 0;
	for (auto& currpart : m_parts)
	{
		bool nearsymbol = false;
		for (auto& currpartpos : currpart.positions)
		{
			std::vector<coord> postocheck = GetAdj(currpartpos);
			for (auto& currsympos : m_sym)
			{
				for (auto& currposcheck : postocheck)
				{
					if (currsympos.col == currposcheck.col && currsympos.row == currposcheck.row)
					{
						nearsymbol = true;
					}

				}
			}
		}
		if (nearsymbol)
		{
			sum += currpart.value;
		}
	}
	return sum;
}

int Day3::Part2()
{
	int sum = 0;
	for (auto& currgear : m_gears)
	{
		bool nearsymbol = false;
		int gearadjcount = 0;
		std::vector<coord> gearadj = GetAdj(currgear);
		std::vector<part> adjparts;
		for (auto& currgearpos : gearadj)
		{
			for (auto& currpart : m_parts)
			{
				for (auto& currpos : currpart.positions)
				{
					if (currpos.col == currgearpos.col && currpos.row == currgearpos.row)
					{
						bool alreadyexists = false;
						for (auto& existingpart : adjparts)
						{
							if (existingpart.value == currpart.value)
							{
								alreadyexists = true;
							}
						}
						if (!alreadyexists)
						{
							adjparts.push_back(currpart);
						}
					}
				}
			}
			
		}
		if (adjparts.size() == 2)
		{
			sum += adjparts[0].value * adjparts[1].value;
		}
	}
	return sum;
}

bool Day3::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}