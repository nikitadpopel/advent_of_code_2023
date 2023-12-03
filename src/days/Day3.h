#include <vector>
#include <string>

class Day3
{

    public:

        struct coord {
            int row;
            int col;
        };

        struct part {
            std::vector<coord> positions;
            int value;
        };

        Day3();
        int Part1();
        int Part2();
        bool Solve();
        std::vector<coord> GetAdj(coord search);
    private:
        std::vector<std::string> m_vecInput;
        std::vector<part> m_parts;
        std::vector<coord> m_sym;
        std::vector<coord> m_gears;
        
};