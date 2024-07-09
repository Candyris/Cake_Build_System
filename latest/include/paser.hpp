#pragma once
#include "token.hpp"
#include <list>
#include <vector>
#include <map>
#include <stdint.h>
#include <iostream>
namespace Candy
{
    namespace TokenID
    {
        inline int8_t Compile = 0;
        inline int8_t Linker  = 1;
        inline int8_t Output  = 2;
        // additional for later
    };
};

namespace Candy
{
    struct collection 
    {
        std::string token_type;
        Token::TokenValue value;
        void log()
        {
            for (Token::Value val : value)
            {
                std::cout<<"key : "<<val.key << " , value : "<<val.value <<std::endl;
            }
        }
    };
    
    class Parser
    {
    public:
        Parser(Token::Tokens tokens);
        void printCompileCollection();
    private:
        void init();
        collection m_CompileToken = {"Compile"};
        collection m_LinkerToken  = {"Linker"};
        collection m_OutputToken  = {"Output"}; 
        std::map<int,std::string> m_ScopeMap;
    };
};

// we want parsper to pushback tokentype and tokenvalue like 
/* paser []
    {
        compile:scope -------> <token_type, value> <include,game.hpp>
                      |
                      --------> <token_type, value> <include,collison.hpp>
                      |
                      --------> <token_type, value> <include,player.hpp>
                      |
                      --------> <token_type, value> <srcfile,game.cpp>
                      |
                      --------> <token_type, value> <include,sound.hpp>\
    }
    {             
        linker:scope -------> <token_type, value> <include,game.hpp>
                      |
                      --------> <token_type, value> <include,collison.hpp>
                      |
                      --------> <token_type, value> <include,player.hpp>
                      |
                      --------> <token_type, value> <srcfile,game.cpp>
                      |
                      --------> <token_type, value> <include,sound.hpp>
    }


*/