#pragma once 
#include <string>
namespace Candy
{
class FileManger
{
    public:
    static std::string loadStringFromfile(const char* file);
};
};