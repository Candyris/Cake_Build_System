#pragma once
#include "paser.hpp"

namespace Candy
{
    class Scope
    {
    public:
        Scope() = default;
        ~Scope() = default;

        void genCompileCmd(const Candy::collection compileCollection);
        void genLinkerCmd(const Candy::collection linkerCollection);
        void genOutputCmd(const Candy::collection outputCollection);

        std::string executeCmd(const char* prefixedCommand);

    private:
        std::string m_complieCommand;
        std::string m_linkerCommand;
        std::string m_outputCommand;
    };

};