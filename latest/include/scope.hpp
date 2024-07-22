#pragma once
#include "paser.hpp"

namespace Candy
{
    class Scope
    {
    public:
        Scope() = default;
        ~Scope() = default;

        void genGlobalCmd( Candy::collection globalCollection);
        void genCompileCmd( Candy::collection compileCollection);
        void genLinkerCmd( Candy::collection linkerCollection);
        void genOutputCmd( Candy::collection outputCollection);
        std::string getCmd();

    private:
        std::string m_globalCommand;
        std::string m_complieCommand;
        std::string m_linkerCommand;
        std::string m_outputCommand;
    };

};