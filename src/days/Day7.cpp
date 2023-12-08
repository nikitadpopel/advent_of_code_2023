#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <regex>

#include "Day7.h"
#include "../helpers/Reader.h"


bool CompareCards(const Day7::player& b, const Day7::player& a)
{
	if (a.handtype > b.handtype)
	{
		return true;
	}
	else if (a.handtype == b.handtype)
	{
		for (int i = 0; i < 5; i++)
		{
			if (a.hand[i] == b.hand[i])
			{
				continue;
			}
			else if (a.hand[i] > b.hand[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}


Day7::Day7()
{
	m_vecInput = ReadInput("../../inputs/day7.input");
	std::vector<std::string>::iterator iter;
	for (iter = m_vecInput.begin(); iter < m_vecInput.end(); iter++)
	{
		std::vector<int> hand;
		for (auto& ch : *iter)
		{
			if (ch == ' ')
			{
				break;
			}
			hand.push_back(m_cardranks[ch]);
		}
		m_hands.push_back(hand);
		m_bids.push_back(stoi(iter->substr(iter->find(" ") + 1, -1)));
	}

}


double Day7::Part1()
{
	for (auto& hand : m_hands)
	{
		std::vector<int> cardsearch;
		for (auto& card : hand)
		{
			cardsearch.push_back(std::count(hand.begin(), hand.end(), card));
		}
		if (std::count(cardsearch.begin(), cardsearch.end(), 5) == 5)
		{
			m_handtypes.push_back(fiveofakind);
		}
		else if (std::count(cardsearch.begin(), cardsearch.end(), 4) == 4)
		{
			m_handtypes.push_back(fourofakind);
		}
		else if (std::count(cardsearch.begin(), cardsearch.end(), 3) == 3 && std::count(cardsearch.begin(), cardsearch.end(), 2) == 2)
		{
			m_handtypes.push_back(fullhouse);
		}
		else if (std::count(cardsearch.begin(), cardsearch.end(), 3) == 3)
		{
			m_handtypes.push_back(threeofakind);
		}
		else if (std::count(cardsearch.begin(), cardsearch.end(), 2) == 4)
		{
			m_handtypes.push_back(twopair);
		}
		else if (std::count(cardsearch.begin(), cardsearch.end(), 2) == 2)
		{
			m_handtypes.push_back(onepair);
		}
		else
		{
			m_handtypes.push_back(highcard);
		}
	}
	for (int i = 0; i < m_hands.size(); i++)
	{
		m_players.push_back({ m_hands[i], m_bids[i], m_handtypes[i] });
	}

	std::sort(m_players.begin(), m_players.end(), CompareCards);
	int totalwinning = 0;
	for (int i = 0; i < m_players.size(); i++)
	{
		totalwinning += m_players[i].bid * (i + 1);
	}
	return totalwinning;
}

double Day7::Part2()
{
	m_handtypes.clear();
	m_players.clear();
	for (auto& hand : m_hands)
	{
		std::vector<int> cardsearch;
		for (auto& card : hand)
		{
			if (card == 11)
			{
				card = 1;
			}
		}
		for (auto& card : hand)
		{
			cardsearch.push_back(std::count(hand.begin(), hand.end(), card));
		}
		if (std::count(cardsearch.begin(), cardsearch.end(), 5) == 5)
		{
			m_handtypes.push_back(fiveofakind);
		}
		else if (std::count(cardsearch.begin(), cardsearch.end(), 4) == 4)
		{
			if (std::count(hand.begin(), hand.end(), 1) == 1)
			{
				m_handtypes.push_back(fiveofakind);
			}
			else
			{
				m_handtypes.push_back(fourofakind);
			}
		}
		else if (std::count(cardsearch.begin(), cardsearch.end(), 3) == 3 && std::count(cardsearch.begin(), cardsearch.end(), 2) == 2)
		{
			if (std::count(hand.begin(), hand.end(), 1) > 2)
			{
				m_handtypes.push_back(fiveofakind);
			}
			else
			{
				m_handtypes.push_back(fullhouse);
			}
		}
		else if (std::count(cardsearch.begin(), cardsearch.end(), 3) == 3)
		{

			if (std::count(hand.begin(), hand.end(), 1) == 2)
			{
				m_handtypes.push_back(fiveofakind);
			}
			else if (std::count(hand.begin(), hand.end(), 1) == 1)
			{
				m_handtypes.push_back(fourofakind);
			}
			else
			{
				m_handtypes.push_back(threeofakind);
			}
		}
		else if (std::count(cardsearch.begin(), cardsearch.end(), 2) == 4)
		{
			if (std::count(hand.begin(), hand.end(), 1) == 1)
			{
				m_handtypes.push_back(threeofakind);
			}
			else if (std::count(hand.begin(), hand.end(), 1) == 2)
			{
				m_handtypes.push_back(fourofakind);
			}
			else
			{
				m_handtypes.push_back(twopair);
			}
			
		}
		else if (std::count(cardsearch.begin(), cardsearch.end(), 2) == 2)
		{
			if (std::count(hand.begin(), hand.end(), 1) == 1)
			{
				m_handtypes.push_back(threeofakind);
			}
			else
			{
				m_handtypes.push_back(onepair);
			}
		}
		else
		{
			m_handtypes.push_back(highcard);
		}
	}
	for (int i = 0; i < m_hands.size(); i++)
	{
		m_players.push_back({ m_hands[i], m_bids[i], m_handtypes[i] });
	}

	std::sort(m_players.begin(), m_players.end(), CompareCards);
	int totalwinning = 0;
	for (int i = 0; i < m_players.size(); i++)
	{
		totalwinning += m_players[i].bid * (i + 1);
	}
	return totalwinning;
}

bool Day7::Solve()
{
	//std::cout << Part1() <<std::endl;
	std::cout << Part2() <<std::endl;

	return true;
}