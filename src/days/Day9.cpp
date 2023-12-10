#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <regex>

#include "Day9.h"
#include "../helpers/Reader.h"


Day9::Day9()
{
	m_vecInput = ReadInput("../../inputs/Day9.input");
	for (auto& input : m_vecInput)
	{
		std::string currline = input;
		std::vector<int> history;
		while(!currline.empty())
		{
			if (currline.find(" ") == std::string::npos)
			{
				history.push_back(stoi(currline));
				currline = "";
			}
			else
			{
				history.push_back(stoi(currline.substr(0, currline.find(" "))));
				currline = currline.substr(currline.find(" ") + 1, -1);
			}
		}
		m_histories.push_back(history);
	}
}

bool AllZeroDelta(std::vector<std::vector<int>> currcalc)
{
	for (auto& check : *(currcalc.end()-1))
	{
		if (check != 0)
		{
			return false;
		}
	}
	return true;
}

double Day9::Part1()
{
	int sums = 0;
	for (auto& history : m_histories)
	{
		std::vector<std::vector<int>> currcalc;
		currcalc.push_back(history);
		while (!AllZeroDelta(currcalc))
		{
			std::vector<int> newdelta;
			for (int i = 1; i < (currcalc.end() - 1)->size(); i++)
			{
				newdelta.push_back(currcalc[currcalc.size()-1][i] - currcalc[currcalc.size() - 1][i - 1]);
			}
			currcalc.push_back(newdelta);
		}
		for (int i = currcalc.size() - 2; i > -1; i--)
		{
			currcalc[i].push_back(currcalc[i + 1][currcalc[i + 1].size() - 1] + currcalc[i][currcalc[i].size() - 1]);
		}
		sums += currcalc[0][currcalc[0].size() - 1];
	}
	return sums;
}

double Day9::Part2()
{
	int sums = 0;
	for (auto& history : m_histories)
	{
		std::vector<std::vector<int>> currcalc;
		currcalc.push_back(history);
		while (!AllZeroDelta(currcalc))
		{
			std::vector<int> newdelta;
			for (int i = 1; i < (currcalc.end() - 1)->size(); i++)
			{
				newdelta.push_back(currcalc[currcalc.size() - 1][i] - currcalc[currcalc.size() - 1][i - 1]);
			}
			currcalc.push_back(newdelta);
		}
		for (int i = currcalc.size() - 2; i > -1; i--)
		{
			currcalc[i].insert(currcalc[i].begin(), currcalc[i][0] - currcalc[i + 1][0]);
		}
		sums += currcalc[0][0];
	}
	return sums;
}

bool Day9::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}