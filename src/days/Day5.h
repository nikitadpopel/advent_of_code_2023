#include <vector>
#include <string>

class Day5
{

    public:


        struct mapping {
            double deststart;
            double sourcestart;
            double rangelen;
            double sourceend;
        };

        Day5();
        double Part1();
        double Part2();
        bool Solve();
    private:
        std::vector<std::string> m_vecInput;
        std::vector<double> m_seeds;
        std::vector<mapping> m_soilmaps;
        std::vector<mapping> m_fertmaps;
        std::vector<mapping> m_watermaps;
        std::vector<mapping> m_lightmaps;
        std::vector<mapping> m_tempmaps;
        std::vector<mapping> m_humidmaps;
        std::vector<mapping> m_locmaps;
};