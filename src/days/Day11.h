#include <vector>
#include <string>
#include <map>

class Day11
{

    struct coord {
        int row;
        int col;
    };

    public:
        Day11();
        double Part1();
        double Part2();
        bool Solve();
    private:
        std::vector<std::string> m_vecInput;
        std::vector<coord> m_galax;
        std::vector<int> m_xempty;
        std::vector<int> m_yempty;
        std::vector<std::vector<coord>> m_pair;
};