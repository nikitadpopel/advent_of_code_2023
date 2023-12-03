#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Reader.h"

std::vector<std::string> ReadInput(std::string inputString)
{
    std::vector<std::string> returnVec;
    std::string line;
    std::ifstream targetFile;
    targetFile.open(inputString);
    if(targetFile.is_open())
    {
        while(std::getline(targetFile,line))
        {
            returnVec.push_back(line);
        }
    }
    if (returnVec.empty())
    {
        std::cout << "ERROR: The file was not read properly" << std::endl;
    }
    
    return returnVec;
}