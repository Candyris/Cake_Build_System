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
        void log()
        {
            for (Token::Value val : value)
            {
                std::cout<<"key : "<<val.key << " , value : "<<val.value <<std::endl;
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