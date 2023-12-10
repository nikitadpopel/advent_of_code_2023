#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <regex>

#include "Day8.h"
#include "../helpers/Reader.h"


Day8::Day8()
{
	m_vecInput = ReadInput("../../inputs/Day8.input");
	m_inst = m_vecInput[0];
	for (int i = 2; i < m_vecInput.size(); i++)
	{
		std::string currInput = m_vecInput[i];
		node currNode;
		currNode.head = currInput.substr(0, currInput.find(" "));
		currInput = currInput.substr(currInput.find("(") + 1, -1);
		currNode.left = currInput.substr(0, currInput.find(", "));
		currInput = currInput.substr(currInput.find(", ") +2, -1);
		currNode.right = currInput.substr(0, currInput.find(")"));
		m_nodes.push_back(currNode);
	}
}


double Day8::Part1()
{
	std::string currNode = "AAA";
	int steps = 0;
	while (currNode != "ZZZ")
	{
		for (auto& ch : m_inst)
		{
			for (auto& node : m_nodes)
			{
				if (node.head == currNode)
				{
					if (ch == 'R')
					{
						currNode = node.right;
						steps++;
					}

					if (ch == 'L')
					{
						currNode = node.left;
						steps++;
					}
					break;
				}
			}
			if (currNode == "ZZZ")
			{
				break;
			}
		}
	}
	return steps;
}

double GCDof2(double a, double b)
{
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

double Day8::Part2()
{
	std::vector<std::string> currNodes;
	for (auto& node : m_nodes)
	{
		if (*(node.head.end()-1) == 'A')
		{
			currNodes.push_back(node.head);
		}
	}
	std::vector<double> stepslist;
	for (auto& currNode : currNodes)
	{
		double steps = 0;
		while (*(currNode.end() - 1) != 'Z')
		{
			for (auto& ch : m_inst)
			{
				for (auto& node : m_nodes)
				{
					if (node.head == currNode)
					{
						if (ch == 'R')
						{
							currNode = node.right;
						}

						if (ch == 'L')
						{
							currNode = node.left;
						}
						break;
					}
				}
				steps++;
				if (*(currNode.end() - 1) == 'Z')
				{
					break;
				}
			}
		}
		stepslist.push_back(steps);
		
	}
	double result = stepslist[0];

	int product = 1;
	for (int i = 1; i < stepslist.size(); i++)
	{
		double currval = result * stepslist[i];
		double GCD = GCDof2(result, stepslist[i]);
		result = currval/GCD;
	}
	return result;
}

bool Day8::Solve()
{
	std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}