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

int Day5::Part1()
{

	std::vector<std::string>::iterator iter;
	int sum = 0;
	for (iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++)
	{
		if (!iter->empty())
		{
			
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