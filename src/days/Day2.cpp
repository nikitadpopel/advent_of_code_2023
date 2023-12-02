#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>

#include "Day2.h"
#include "../helpers/Reader.h"

Day2::Day2()
{
	m_vecInput = ReadInput("C:\\Users\\mpopel\\Documents\\github\\advent_of_code_2023\\src\\inputs\\day2.input");
}

int Day2::Part1()
{
	int s_red = 12;
	int s_green = 13;
	int s_blue = 14;
	int id_sum = 0;
	std::vector<std::string>::iterator iter;
	for(iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++ )
	{
		if(!iter->empty())
		{
			int curr_id = stoi(iter->substr(iter->find(" "), iter->find(":")));
			std::string rounds_str = iter->substr(iter->find(":") + 2, -1);
			std::vector<std::string> rounds;
			while(!rounds_str.empty())
			{
				auto delim_i = rounds_str.find(",");
				auto sc_i = rounds_str.find(";");
				if (delim_i != std::string::npos)
				{
					if(sc_i != std::string::npos && sc_i < delim_i)
					{
						delim_i = sc_i;
					}
				}
				else if (sc_i != std::string::npos)
				{
					delim_i = sc_i;
				}
				if(delim_i != std::string::npos)
				{
					rounds.push_back(rounds_str.substr(0, delim_i));
					rounds_str = rounds_str.substr(delim_i + 2, -1);
				}
				else
				{
					rounds.push_back(rounds_str);
					rounds_str = "";
				}
				
			}
			bool is_possible = true;
			for (auto & element : rounds)
			{
				int val = stoi(element.substr(0, element.find(" ")));
				if(element.find("red") != std::string::npos && val > s_red)
				{
					is_possible = false;
				}
				if(element.find("green") != std::string::npos && val > s_green)
				{
					is_possible = false;
				}
				if(element.find("blue") != std::string::npos && val > s_blue)
				{
					is_possible = false;
				}
			}
			if(is_possible)
			{
				id_sum += curr_id;
			}
		}
	}


	return id_sum;
}

int Day2::Part2()
{
	int s_red = 12;
	int s_green = 13;
	int s_blue = 14;
	int id_sum = 0;
	std::vector<std::string>::iterator iter;
	for(iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++ )
	{
		if(!iter->empty())
		{
			int curr_id = stoi(iter->substr(iter->find(" "), iter->find(":")));
			std::string rounds_str = iter->substr(iter->find(":") + 2, -1);
			std::vector<std::string> rounds;
			while(!rounds_str.empty())
			{
				auto delim_i = rounds_str.find(",");
				auto sc_i = rounds_str.find(";");
				if (delim_i != std::string::npos)
				{
					if(sc_i != std::string::npos && sc_i < delim_i)
					{
						delim_i = sc_i;
					}
				}
				else if (sc_i != std::string::npos)
				{
					delim_i = sc_i;
				}
				if(delim_i != std::string::npos)
				{
					rounds.push_back(rounds_str.substr(0, delim_i));
					rounds_str = rounds_str.substr(delim_i + 2, -1);
				}
				else
				{
					rounds.push_back(rounds_str);
					rounds_str = "";
				}
				
			}
			int max_red = 0;
			int max_green = 0;
			int max_blue = 0;
			for (auto & element : rounds)
			{
				int val = stoi(element.substr(0, element.find(" ")));
				if(element.find("red") != std::string::npos && val > max_red)
				{
					max_red = val;
				}
				if(element.find("green") != std::string::npos && val > max_green)
				{
					max_green = val;
				}
				if(element.find("blue") != std::string::npos && val > max_blue)
				{
					max_blue = val;
				}
			}
			id_sum += max_red * max_green * max_blue;

		}
	}


	return id_sum;
}

bool Day2::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}