#ifndef FILEMANGER_HPP
#include <string>


#define CAKEBUILD_FILEPATH "cake.make"

namespace Candy
{
    
class FileManger
{
    public:
    static std::string loadStringFromfile(const char* file);
    static void createFileWithContext (const char* filename,const char* context);
};
};
#endif