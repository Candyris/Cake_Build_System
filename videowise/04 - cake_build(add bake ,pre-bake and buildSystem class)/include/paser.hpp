#pragma once
#include "token.hpp"
#include <list>
#include <vector>
#include <map>
#include <stdint.h>
#include <iostream>
namespace Candy
{
    struct collection 
    {
        std::string token_type;
        std::vector<Candy::Token::Value> value;
        std::vector<Token::Value>::iterator it;
        void incrementIT(){it++;}
        void log()
        {
            for (std::vector<Token::Value>::iterator iter = value.begin(); iter != value.end() ; iter++)
            {
                std::cout<<"key : "<<iter->first << " , value : "<<iter->second <<std::endl;
            }
        }
    };
};

namespace Candy
{
   
    collection Parser (Token::Tokens tokens , Candy::Token::Tokens reservedtokencollection, std::string ScopeTarget);
   
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