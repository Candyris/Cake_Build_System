#pragma once
#include "../include/filemanger.hpp"
#include <fstream>
#include <string>
#include <string.h>
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



void Candy::FileManger::createFileWithContext(const char *filename, const char *context)
{
    std::ofstream outfile;
    outfile.open(filename);
    outfile.write(context,strlen(context));
    outfile.close();
}
