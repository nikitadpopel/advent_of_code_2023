#include <vector>
#include <string>
#include <map>

class Day8
{
    public:
        struct node {
            std::string head;
            std::string left;
            std::string right;       
        };
        Day8();
        double Part1();
        double Part2();
        bool Solve();
    private:
        std::vector<std::string> m_vecInput;
        std::string m_inst;
        std::vector<node> m_nodes;
};