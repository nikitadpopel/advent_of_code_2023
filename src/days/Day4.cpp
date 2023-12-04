#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>

#include "Day4.h"
#include "../helpers/Reader.h"


Day4::Day4()
{
	m_vecInput = ReadInput("inputs/day4.input");
	std::vector<std::string>::iterator iter;

	for(iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++ )
	{
		if(!iter->empty())
		{
			

		}
	}
}

int Day4::Part1()
{
	return 0;
}

int Day4::Part2()
{
	return 0;
}

bool Day4::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}