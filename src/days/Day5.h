#include <vector>
#include <string>

class Day5
{

    public:


        struct mapping {
            float deststart;
            float sourcestart;
            float rangelen;
            float sourceend;
        };

        Day5();
        float Part1();
        float Part2();
        bool Solve();
    private:
        std::vector<std::string> m_vecInput;
        std::vector<float> m_seeds;
        std::vector<mapping> m_soilmaps;
        std::vector<mapping> m_fertmaps;
        std::vector<mapping> m_watermaps;
        std::vector<mapping> m_lightmaps;
        std::vector<mapping> m_tempmaps;
        std::vector<mapping> m_humidmaps;
        std::vector<mapping> m_locmaps;
};