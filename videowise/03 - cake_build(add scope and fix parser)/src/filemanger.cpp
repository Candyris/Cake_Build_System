#include "../include/filemanger.hpp"
#include <fstream>
#include <string>

namespace Candy
{
 std::string FileManger::loadStringFromfile(const char* file)
 {
    std::ifstream infile(file); // open the file 

    std::string line;
    std::string filecode ="";
    while (getline(infile,line))
    {
        filecode += line + '\n';
    }
    infile.close();
    return filecode;
 }
};