#include <vector>
#include <string>
#include <map>

class Day7
{

    public:
        
        enum handtype
        {
            highcard = 0,
            onepair = 1,
            twopair = 2,
            threeofakind = 3,
            fullhouse = 4,
            fourofakind = 5,
            fiveofakind = 6
        };

        struct player {
            std::vector<int> hand;
            int bid;
            handtype handtype;
        };
        Day7();
        double Part1();
        double Part2();
        bool Solve();
    private:
        std::vector<std::string> m_vecInput;
        std::map<char, int> m_cardranks = { {'2', 2},
                                        {'3', 3},
                                        {'4', 4},
                                        {'5', 5},
                                        {'6', 6},
                                        {'7', 7},
                                        {'8', 8},
                                        {'9', 9},
                                        {'T', 10},
                                        {'J', 11},
                                        {'Q', 12},
                                        {'K', 13},
                                        {'A', 14}};
        std::vector<std::vector<int>> m_hands;
        std::vector<int> m_bids;
        std::vector<handtype> m_handtypes;
        std::vector<player> m_players;
};