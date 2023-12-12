#include <vector>
#include <string>
#include <map>

class Day10
{

    enum pos {
        up = 0,
        right = 1,
        down = 2,
        left = 3
    };

    struct coord {
        int row;
        int col;
    };
    
    struct node {
        coord curr;
        coord prev;
    };

    public:
        
        bool IsConnected(coord currNode, coord potential);

        Day10();
        double Part1();
        double Part2();
        bool Solve();
    private:
        std::vector<std::string> m_vecInput;
        std::vector<std::vector<char>> m_grid;
        coord m_start;
        std::string upface = "|7F";
        std::string rightface = "-J7";
        std::string downface = "|LJ";
        std::string leftface = "-LF";
        std::vector<coord> loopspots;

        std::string leftsidesearch = "|LJ7F";
        std::vector<coord> enclosed;
};