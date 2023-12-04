#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <regex>

#include "Day4.h"
#include "../helpers/Reader.h"


Day4::Day4()
{
	m_vecInput = ReadInput("../../inputs/day4.input");
}

int Day4::Part1()
{

	std::vector<std::string>::iterator iter;
	int sum = 0;
	for (iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++)
	{
		if (!iter->empty())
		{
			std::string trim_iter = iter->substr(iter->find(":") + 1, -1);
			std::string win_num = trim_iter.substr(1, trim_iter.find("|") - 1);
			std::string you_num = trim_iter.substr(trim_iter.find("|")+2, -1);
			int score = 0;
			std::vector<std::string> win_nums;
			while (!win_num.empty())
			{
				std::string curr_num = win_num.substr(0, win_num.find(" "));
				win_num = win_num.substr(win_num.find(" ") + 1, -1);
				win_nums.push_back(curr_num);
			}
			bool doneiter = false;
			while (!doneiter)
			{
				auto itr = std::find(win_nums.begin(), win_nums.end(), "");
				if (itr == win_nums.end())
				{
					doneiter = true;
				}
				else
				{
					win_nums.erase(itr);
				}
			}
			int temp = 0;
			you_num = std::regex_replace(you_num, std::regex("  "), " ");
			bool linedone = false;
			while (!you_num.empty())
			{
				std::string curr_num;
				
				if (you_num.find(" ") == std::string::npos)
				{
					curr_num = you_num;
					linedone = true;
				}
				else
				{
					curr_num = you_num.substr(0, you_num.find(" "));
				}
				you_num = you_num.substr(you_num.find(" ") + 1, -1);
				int count = 0;
				for (int i = 0; i < win_nums.size(); i++)
				{
					if (win_nums[i] == curr_num)
					{
						bool doneiter = false;
						while (!doneiter)
						{
							auto itr = std::find(win_nums.begin(), win_nums.end(), curr_num);
							if (itr == win_nums.end())
							{
								doneiter = true;
							}
							else
							{
								win_nums.erase(itr);

							}
						}
						if (score == 0)
						{
							score += 1;
						}
						else
						{
							score *= 2;
						}
					}
					count++;
				}

				if (linedone)
				{
					you_num = "";
				}
			}
			sum += score;
		}
	}
	return sum;
}

int Day4::Part2()
{
	std::vector<std::string>::iterator iter;
	int sum = 0;
	std::vector<int> counts;
	counts.push_back(0);
	counts.push_back(1);
	int currcount = 1;
	for (iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++)
	{
		if (counts.size() - 1 < currcount)
		{
			counts.push_back(1);
		}
		if (!iter->empty())
		{
			std::string trim_iter = iter->substr(iter->find(":") + 1, -1);
			std::string win_num = trim_iter.substr(1, trim_iter.find("|") - 1);
			std::string you_num = trim_iter.substr(trim_iter.find("|") + 2, -1);
			int score = 0;
			std::vector<std::string> win_nums;
			while (!win_num.empty())
			{
				std::string curr_num = win_num.substr(0, win_num.find(" "));
				win_num = win_num.substr(win_num.find(" ") + 1, -1);
				win_nums.push_back(curr_num);
			}
			bool doneiter = false;
			while (!doneiter)
			{
				auto itr = std::find(win_nums.begin(), win_nums.end(), "");
				if (itr == win_nums.end())
				{
					doneiter = true;
				}
				else
				{
					win_nums.erase(itr);
				}
			}
			int temp = 0;
			you_num = std::regex_replace(you_num, std::regex("  "), " ");
			bool linedone = false;
			while (!you_num.empty())
			{
				std::string curr_num;

				if (you_num.find(" ") == std::string::npos)
				{
					curr_num = you_num;
					linedone = true;
				}
				else
				{
					curr_num = you_num.substr(0, you_num.find(" "));
				}
				you_num = you_num.substr(you_num.find(" ") + 1, -1);
				for (int i = 0; i < win_nums.size(); i++)
				{
					if (win_nums[i] == curr_num)
					{
						bool doneiter = false;
						while (!doneiter)
						{
							auto itr = std::find(win_nums.begin(), win_nums.end(), curr_num);
							if (itr == win_nums.end())
							{
								doneiter = true;
							}
							else
							{
								win_nums.erase(itr);

							}
						}
						score += 1;
					}
				}

				if (linedone)
				{
					you_num = "";
				}
			}
			for (int i = 1; i < score + 1; i++)
			{
				if (counts.size() - 1< currcount + i)
				{
					counts.push_back(1);
				}
				counts[currcount + i] += counts[currcount];
			}
		}

		currcount ++;
	}
	int retsum = 0;
	for (int i = 0; i < counts.size(); i++)
	{
		retsum += counts[i];
	}
	return retsum;
}

bool Day4::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}