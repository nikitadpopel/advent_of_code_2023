#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <regex>

#include "Day11.h"
#include "../helpers/Reader.h"


Day11::Day11()
{
	m_vecInput = ReadInput("../../inputs/Day11.input");
	for (int y = 0; y < m_vecInput.size(); y++)
	{
		bool isempty = true;
		for (int x = 0; x < m_vecInput[y].size(); x++)
		{
			if (m_vecInput[y][x] == '#')
			{
				isempty = false;
				m_galax.push_back({ y, x });
			}
		}
		if (isempty)
		{
			m_yempty.push_back(y);
		}
	}
	for (int x = 0; x < m_vecInput[0].size(); x++)
	{
		bool isempty = true;
		for (int y = 0; y < m_vecInput.size(); y++)
		{
			if (m_vecInput[y][x] == '#')
			{
				isempty = false;
			}
		}
		if (isempty)
		{
			m_xempty.push_back(x);
		}
	}
	for (auto& currgalax : m_galax)
	{
		for (auto& othergalax : m_galax)
		{
			if (currgalax.col == othergalax.col && currgalax.row == othergalax.row)
			{
				continue;
			}
			bool isfound = false;
			for (auto& pair : m_pair)
			{
				if ((pair[0].col == currgalax.col && pair[0].row == currgalax.row && pair[1].col == othergalax.col && pair[1].row == othergalax.row) ||
					(pair[1].col == currgalax.col && pair[1].row == currgalax.row && pair[0].col == othergalax.col && pair[0].row == othergalax.row))
				{
					isfound = true;
				}
			}
			if (!isfound)
			{
				m_pair.push_back({ currgalax, othergalax });
			}
		}
	}
}


double Day11::Part1()
{
	int totalsum = 0;
	for (auto& pair : m_pair)
	{
		int deltax = pair[0].col - pair[1].col;
		if (deltax == 0)
		{
			
		}
		if (deltax > 0)
		{
			int xcount = 0;
			for (int i = 0; i < deltax; i++)
			{
				for (auto& emptyx : m_xempty)
				{
					if (pair[1].col + i == emptyx)
					{
						xcount++;
					}
				}
			}
			deltax += xcount;
		}
		if (deltax < 0)
		{
			int xcount = 0;
			for (int i = 0; i > deltax; i--)
			{
				for (auto& emptyx : m_xempty)
				{
					if (pair[1].col + i == emptyx)
					{
						xcount++;
					}
				}
			}

			if (deltax < 0)
			{
				deltax *= -1;
			}
			deltax += xcount;
		}
		
		int deltay = pair[0].row - pair[1].row;
		if (deltay == 0)
		{

		}
		if (deltay > 0)
		{
			int ycount = 0;
			for (int i = 0; i < deltay; i++)
			{
				for (auto& emptyy : m_yempty)
				{
					if (pair[1].row + i == emptyy)
					{
						ycount++;
					}
				}
			}
			deltay += ycount;
		}
		if (deltay < 0)
		{
			int ycount = 0;
			for (int i = 0; i > deltay; i--)
			{
				for (auto& emptyy : m_yempty)
				{
					if (pair[1].row + i == emptyy)
					{
						ycount++;
					}
				}
			}
			if (deltay < 0)
			{
				deltay *= -1;
			}
			deltay += ycount;
		}
		totalsum += deltax + deltay;
	}

	return totalsum;
}

double Day11::Part2()
{
	double totalsum = 0;
	for (auto& pair : m_pair)
	{
		double deltax = pair[0].col - pair[1].col;
		if (deltax == 0)
		{

		}
		if (deltax > 0)
		{
			double xcount = 0;
			for (double i = 0; i < deltax; i++)
			{
				for (auto& emptyx : m_xempty)
				{
					if (pair[1].col + i == emptyx)
					{
						xcount+= 999999;
					}
				}
			}
			deltax += xcount;
		}
		if (deltax < 0)
		{
			double xcount = 0;
			for (double i = 0; i > deltax; i--)
			{
				for (auto& emptyx : m_xempty)
				{
					if (pair[1].col + i == emptyx)
					{
						xcount+= 999999;
					}
				}
			}

			if (deltax < 0)
			{
				deltax *= -1;
			}
			deltax += xcount;
		}

		double deltay = pair[0].row - pair[1].row;
		if (deltay == 0)
		{

		}
		if (deltay > 0)
		{
			double ycount = 0;
			for (double i = 0; i < deltay; i++)
			{
				for (auto& emptyy : m_yempty)
				{
					if (pair[1].row + i == emptyy)
					{
						ycount+=999999;
					}
				}
			}
			deltay += ycount;
		}
		if (deltay < 0)
		{
			double ycount = 0;
			for (double i = 0; i > deltay; i--)
			{
				for (auto& emptyy : m_yempty)
				{
					if (pair[1].row + i == emptyy)
					{
						ycount+=999999;
					}
				}
			}
			if (deltay < 0)
			{
				deltay *= -1;
			}
			deltay += ycount;
		}
		totalsum += deltax + deltay;
	}

	return totalsum;
}

bool Day11::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}