#include "../include/token_type.hpp"
#include "../include/paser.hpp"
#include <map>
#include <algorithm>
#include <iostream>
namespace Candy
{
    std::map<int8_t, std::string> scopeMap;

    std::list<std::string> CompileTokenType{"include", "srcfile"};
    std::list<std::string> LinkerTokenType{"link_lib", "link_spefic"};
    std::list<std::string> OutputTokenType{"outfile"};

    /* Parser::Parser(Tokens tokens)
     {
     }
     */
}

Candy::Parser::Parser(Token::Tokens tokens)
{
    init();
    // variables
    std::string _selectScopeTarget = "";
    std::string _lastKey = "";
    std::string _lastValue = "";
    bool _braketOpen = false;
    for (std::string token : tokens) // checking which scope are in. Like compile
    {
        if (token == m_ScopeMap[Candy::TokenID::Compile])
        {
            _selectScopeTarget = m_ScopeMap[Candy::TokenID::Compile];
            continue;
        }

        if (token == "{") // good
        {
        }
        else if (token == "}") // good
        {
            _selectScopeTarget = "";
        }
        else
        {
            if (_selectScopeTarget == m_ScopeMap[Candy::TokenID::Compile]) // good
            {

                if (_lastKey.empty())
                {
                    std::cout << " lastkey empty token :" << token << std::endl;
                    std::list<std::string>::iterator iter = std::find(CompileTokenType.begin(), CompileTokenType.end(), token);
                    if (iter != CompileTokenType.end())
                    {
                        _lastKey = token;
                    }
                }
                else if (token == "(") // good
                {
                    _braketOpen = true;
                }

                else if (token == ")") // good 
                {
                    _braketOpen = false;
                    m_CompileToken.value.push_back(Token::Value(_lastKey, _lastValue));
                    _lastKey = "";
                    _lastValue = "";
                }
                else if (_braketOpen)
                {
                    _lastValue += token;
                }
            }
        }
    }
}

void Candy::Parser::printCompileCollection()
{
    std::cout<<"------------------------Compile Collection----------------------\n";
        m_CompileToken.log();

    std::cout << "--------------- ----End----- --------------------------\n";

}

// that for this video

void Candy::Parser::init()
{
    m_ScopeMap[Candy::TokenID::Compile] = "compile";
    m_ScopeMap[Candy::TokenID::Linker] = "linker";
    m_ScopeMap[Candy::TokenID::Output] = "output";
}

// later in the paser constructor {
/*else if (token == m_ScopeMap[Candy::TokenID::Linker])
        {
            _selectScopeTarget = m_ScopeMap[Candy::TokenID::Linker];
            continue;
        }
        else if (token == m_ScopeMap[Candy::TokenID::Output])
        {
            _selectScopeTarget = m_ScopeMap[Candy::TokenID::Output];
            continue;
        }
}*/
