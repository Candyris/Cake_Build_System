#pragma once
#include "cake.hpp"
namespace Candy
{

    class BuildSystem
    {
        public:
        BuildSystem() = default;
        ~BuildSystem() = default;

        void LoadFile(const char* filepath);
        void generateToken();
        void generateCommand();
        void runCommand(const char *link= "");
        private:
        std::string m_CommandPrompt;
        std::string m_Filecode;
        collection m_GlobalCollection;
        collection m_CompileCollection;
        collection m_LinkerCollection;
        collection m_OutputCollection;
        Candy::Scope scope;

    };

};