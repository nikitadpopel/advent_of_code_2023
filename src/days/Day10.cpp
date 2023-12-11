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
	int steps = 1;
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
		}
		steps++;
	}
	return 0;
}

double Day10::Part2()
{
	return 0;
}

bool Day10::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}