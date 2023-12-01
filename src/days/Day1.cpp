#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

#include "Day1.h"
#include "../helpers/Reader.h"

Day1::Day1()
{
	m_vecInput = ReadInput("C:\\Users\\mpopel\\Documents\\github\\advent_of_code_2023\\src\\inputs\\day1.input");
}

int Day1::Part1()
{
	std::vector<std::string>::iterator iter;
	int sum = 0;
	for(iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++ )
	{
		if(!iter->empty())
		{
			std::string str = *iter;
			std::vector<int> values;
			for(char& c : str) 
			{
				int val = c - '0';
				if (val > -1 && val < 10)
				{
					values.push_back(val);
				}
			}
			sum += 10 * values.front() + values.back();
		}
	}
	return sum;
}

int Day1::Part2()
{
	std::vector<std::string>::iterator iter;
	int sum = 0;
	std::unordered_map<std::string, int> valuesearch;
	valuesearch["0"] = 0;
	valuesearch["1"] = 1;
	valuesearch["2"] = 2;
	valuesearch["3"] = 3;
	valuesearch["4"] = 4;
	valuesearch["5"] = 5;
	valuesearch["6"] = 6;
	valuesearch["7"] = 7;
	valuesearch["8"] = 8;
	valuesearch["9"] = 9;
	valuesearch["one"] = 1;
	valuesearch["two"] = 2;
	valuesearch["three"] = 3;
	valuesearch["four"] = 4;
	valuesearch["five"] = 5;
	valuesearch["six"] = 6;
	valuesearch["seven"] = 7;
	valuesearch["eight"] = 8;
	valuesearch["nine"] = 9;
	for(iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++ )
	{
		if(!iter->empty())
		{
			std::string str = *iter;
			std::vector<int> values;
			while (!str.empty())
			{
				for (auto i : valuesearch)
				{
					if(str.find(i.first) == 0)
					{
						values.push_back(i.second);
					}
				}
				str.erase(0,1);
			}
			sum += 10 * values.front() + values.back();
		}
	}
	return sum;
}

bool Day1::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}