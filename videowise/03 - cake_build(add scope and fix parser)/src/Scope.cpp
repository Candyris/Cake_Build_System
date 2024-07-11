#include "../include/scope.hpp"
void Candy::Scope::genCompileCmd( Candy::collection compileCollection)
{
    for (Candy::Token::Value val : compileCollection.value) // bad
    {
        std::cout<<"TOKEN : KEY -> "<<val.key << " VALUE -> "<<val.value <<std::endl;
        if (!val.key.find("include_dir")) // bad 
        {
            m_complieCommand += "-I./";
            m_complieCommand += val.value + " ";
        }
        else if (!val.key.find("srcfile"))
        {
            m_complieCommand += val.value + " ";
        }
    }
}

void Candy::Scope::genLinkerCmd(const Candy::collection linkerCollection)
{
    for (Candy::Token::Value val : linkerCollection.value)
    {
        if (val.key == "link_dir")
        {
            m_linkerCommand += "-L./";
            m_linkerCommand += val.value + " ";
        }
        else if (val.key == "attach")
        {
            std::cout<<"linker"<<val.key<<std::endl;
            m_linkerCommand +="-l";
            m_linkerCommand += val.value + " ";
        }
    }
}

void Candy::Scope::genOutputCmd(const Candy::collection outputCollection)
{
    for(Candy::Token::Value val : outputCollection.value)
        if (val.key == "outfile")
            m_outputCommand += "-o " + val.value + " ";


}

std::string Candy::Scope::executeCmd(const char* prefixedCommand)
{
    std::string space = "  ";
    #ifdef _WIN32
    std::string cmd = prefixedCommand +space+ m_complieCommand +space+ m_linkerCommand +space+ m_outputCommand + "-mwindows";
    #else
    std::string cmd = prefixedCommand +space+ m_complieCommand +space+ m_linkerCommand +space+ m_outputCommand ;
    #endif
    system(cmd.c_str());
    return cmd;
}
