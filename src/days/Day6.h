#include <vector>
#include <string>

class Day6
{

    public:
        Day6();
        double Part1();
        double Part2();
        bool Solve();
    private:
        std::vector<std::string> m_vecInput;
        std::vector<int> m_times;
        std::vector<int> m_dists;
        double m_bigtime;
        double m_bigdist;
};