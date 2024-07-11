#include "../include/scope.hpp"
void Candy::Scope::genCompileCmd( Candy::collection compileCollection)
{
    for (compileCollection.it = compileCollection.value.begin(); compileCollection.it != compileCollection.value.end() ; compileCollection.incrementIT()) // bad
    {
       // std::cout<<"TOKEN : KEY -> "<<compileCollection.it->first << " VALUE -> "<<compileCollection.it->second <<std::endl;
        if (!compileCollection.it->first.find("include_dir")) // bad 
        {
            m_complieCommand += "-I./";
            m_complieCommand += compileCollection.it->second + " ";
        }
        else if (!compileCollection.it->first.find("srcfile"))
        {
            m_complieCommand += compileCollection.it->second + " ";
        }
    }
}

void Candy::Scope::genLinkerCmd(const Candy::collection linkerCollection)
{
    for (Candy::Token::Value val : linkerCollection.value)
    {
        if (val.first == "link_dir")
        {
            m_linkerCommand += "-L./";
            m_linkerCommand += val.second + " ";
        }
        else if (val.first == "attach")
        {
            m_linkerCommand +="-l";
            m_linkerCommand += val.second + " ";
        }
    }
}

void Candy::Scope::genOutputCmd(const Candy::collection outputCollection)
{
    for(Candy::Token::Value val : outputCollection.value)
        if (val.first == "outfile")
            m_outputCommand += "-o " + val.second + " ";


}

std::string Candy::Scope::getCmd()
{
    std::string space = "  ";
    std::string cmd = space+ m_complieCommand +space+ m_linkerCommand +space+ m_outputCommand ;

    /*#ifdef _WIN32
    std::string cmd = space+ m_complieCommand +space+ m_linkerCommand +space+ m_outputCommand + "-mwindows";
    #else
    std::string cmd = prefixedCommand +space+ m_complieCommand +space+ m_linkerCommand +space+ m_outputCommand ;
    #endif*/
    return cmd;
}
