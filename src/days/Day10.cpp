#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <regex>

#include "Day10.h"
#include "../helpers/Reader.h"


Day10::Day10()
{
	m_vecInput = ReadInput("../../inputs/Day10.input");
	for (int y = 0; y < m_vecInput.size(); y++)
	{
		std::vector<char> gridline;
		for (int x = 0; x < m_vecInput[y].size(); x++)
		{
			if (m_vecInput[y][x] == 'S')
			{
				m_start = {y,x};
			}
			gridline.push_back(m_vecInput[y][x]);
		}
		m_grid.push_back(gridline);
	}

}

bool Day10::IsConnected(coord currNode, coord potential)
{
	char target = m_grid[potential.row][potential.col];
	pos orient;
	if (currNode.row - potential.row == 1)
	{
		orient = up;
	}
	else if (currNode.row - potential.row == -1)
	{
		orient = down;
	}
	else if (currNode.col - potential.col == 1)
	{
		orient = left;
	}
	else if (currNode.col - potential.col == -1)
	{
		orient = right;
	}

	if (m_grid[currNode.row][currNode.col] == 'S')
	{
		switch (orient) {
		case up:
			if (upface.find(target) != std::string::npos)
			{
				return true;
			}
			return false;
			break;
		case down:
			if (downface.find(target) != std::string::npos)
			{
				return true;
			}
			return false;
			break;
		case left:
			if (leftface.find(target) != std::string::npos)
			{
				return true;
			}
			return false;
			break;
		case right:
			if (rightface.find(target) != std::string::npos)
			{
				return true;
			}
			return false;
			break;

		}

	}

	if (downface.find(m_grid[currNode.row][currNode.col]) != std::string::npos && orient == up)
	{
		return true;
	}

	if (leftface.find(m_grid[currNode.row][currNode.col]) != std::string::npos && orient == right)
	{
		return true;
	}
	if (upface.find(m_grid[currNode.row][currNode.col]) != std::string::npos && orient == down)
	{
		return true;
	}
	if (rightface.find(m_grid[currNode.row][currNode.col]) != std::string::npos && orient == left)
	{
		return true;
	}
	return false;
}

double Day10::Part1()
{
	std::vector<coord> starts;
	std::vector<pos> prevmovement;
	if (m_start.row != 0 && IsConnected(m_start, { m_start.row - 1, m_start.col }))
	{
		starts.push_back({ m_start.row - 1, m_start.col });
		prevmovement.push_back(up);
	}
	if (m_start.row != m_grid.size()-1 && IsConnected(m_start, { m_start.row + 1, m_start.col }))
	{
		starts.push_back({ m_start.row + 1, m_start.col });
		prevmovement.push_back(down);
	}
	if (m_start.col != 0 && IsConnected(m_start, { m_start.row, m_start.col - 1 }))
	{
		starts.push_back({ m_start.row, m_start.col - 1 });
		prevmovement.push_back(left);
	}
	if (m_start.col != m_grid[0].size() - 1 && IsConnected(m_start, { m_start.row, m_start.col + 1}))
	{
		starts.push_back({ m_start.row, m_start.col + 1 });
		prevmovement.push_back(right);
	}

	if (prevmovement[0] == up && prevmovement[1] == down)
	{
		m_grid[m_start.row][m_start.col] = '|';
	}
	if (prevmovement[0] == up && prevmovement[1] == left)
	{
		m_grid[m_start.row][m_start.col] = 'J';
	}
	if (prevmovement[0] == up && prevmovement[1] == right)
	{
		m_grid[m_start.row][m_start.col] = 'L';
	}
	if (prevmovement[0] == down && prevmovement[1] == left)
	{
		m_grid[m_start.row][m_start.col] = '7';
	}
	if (prevmovement[0] == down && prevmovement[1] == right)
	{
		m_grid[m_start.row][m_start.col] = 'F';
	}
	if (prevmovement[0] == left && prevmovement[1] == right)
	{
		m_grid[m_start.row][m_start.col] = '-';
	}

	int steps = 1;
	loopspots.push_back(m_start);
	loopspots.push_back(starts[0]);
	loopspots.push_back(starts[1]);
	while (starts[0].row != starts[1].row || starts[0].col != starts[1].col)
	{
		for (int i = 0; i < starts.size(); i++)
		{
			if (prevmovement[i] != down && starts[i].row != 0 && IsConnected(starts[i], { starts[i].row - 1, starts[i].col}))
			{
				starts[i] = { starts[i].row - 1, starts[i].col };
				prevmovement[i] = up;
			}
			else if (prevmovement[i] != up && starts[i].row != m_grid.size() - 1 && IsConnected(starts[i], { starts[i].row + 1, starts[i].col }))
			{
				starts[i] = { starts[i].row + 1, starts[i].col };
				prevmovement[i] = down;
			}
			else if (prevmovement[i] != right && starts[i].col != 0 && IsConnected(starts[i], { starts[i].row, starts[i].col - 1 }))
			{
				starts[i] = { starts[i].row, starts[i].col - 1 };
				prevmovement[i] = left;
			}
			else if (prevmovement[i] != left && starts[i].col != m_grid[0].size() - 1 && IsConnected(starts[i], { starts[i].row, starts[i].col + 1 }))
			{
				starts[i] = { starts[i].row, starts[i].col + 1 };
				prevmovement[i] = right;
			}

			loopspots.push_back(starts[i]);
		}
		steps++;
	}
	return steps;
}

double Day10::Part2()
{
	for (int y = 0; y < m_grid.size(); y++)
	{
		for (int x = 0; x < m_grid[y].size(); x++)
		{
			bool notfound = true;
			for (auto& spot : loopspots)
			{
				if (spot.row == y && spot.col == x)
				{
					notfound = false;
				}
			}
			if (notfound)
			{
				int intercount = 0;
				std::string intersect = "";
				for (int i = x - 1; i > -1; i--)
				{
					if (leftsidesearch.find(m_grid[y][i]) != std::string::npos)
					{
						bool found = false;
						for (auto& search : loopspots)
						{
							if (search.row == y && search.col == i)
							{
								found = true;
							}
						}
						if (found)
						{
							intersect += m_grid[y][i];
						}
					}
				}
				char currjunc = ' ';
				for (auto& inter : intersect)
				{
					if (inter == '|')
					{
						intercount++;
					}
					if (inter == 'J')
					{
						currjunc = 'J';
					}
					if (inter == '7')
					{
						currjunc = '7';
					}
					if (inter == 'L' && currjunc == 'J')
					{
						intercount+=2;
					}

					if (inter == 'L' && currjunc == '7')
					{
						intercount++;
					}

					if (inter == 'F' && currjunc == '7')
					{
						intercount += 2;
					}

					if (inter == 'F' && currjunc == 'J')
					{
						intercount++;
					}
				}
				if (intercount % 2 == 1)
				{
					enclosed.push_back({y, x});
				}
			}
		}
	}

	return enclosed.size();
}

bool Day10::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}