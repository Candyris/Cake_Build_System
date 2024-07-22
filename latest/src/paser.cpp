#include "../include/token_type.hpp"
#include "../include/paser.hpp"
#include <map>
#include <algorithm>
Candy::collection Candy::ParserKeyword(Token::Tokens tokens, Candy::Token::Tokens reservedtokencollection, std::string ScopeTarget)
{
    Candy::collection collection;
    std::string _selectScopeTarget = "";
    std::string _lastKey = "";
    std::string _lastValue = "";
    bool _colonOpen = false;
    bool _braketOpen = false;
    bool _nextValue = false ; 
    for (std::string token : tokens) // iterate over every element
    {
        if (token == ScopeTarget) // find the target
        {
            _selectScopeTarget = ScopeTarget;
            continue;
        }

        if (token == "{") // open the scopeTarget
        {
            _braketOpen = true;
        }
        else if (token == "}") // reset the scopeTarget
        {
            _braketOpen = false;
            _selectScopeTarget = "";
        } 
        else
        {
            if (_selectScopeTarget == ScopeTarget) // checking if the scopeTarget is selected as pass target
            {
                if (_lastKey.empty()) 
                {
                    std::vector<std::string>::iterator iter = std::find(reservedtokencollection.begin(), reservedtokencollection.end(), token);
                    if (iter != reservedtokencollection.end())
                    {
                        _lastKey = token;
                        _nextValue = true;
                        continue;
                    }
                }
                else if (!token.empty()) // checking for the value 
                {
                    if (token != ":" && _nextValue)
                    {
                        _lastValue += token;
                        collection.value.push_back(Token::Value(_lastKey, _lastValue));
                        _nextValue =false; // close
                        _lastKey = "" ;
                        _lastValue = "";
                    }
                }
                else  // good
                { 
                    _lastKey = "";
                    _lastValue = "";
                }
            }
        }
    }

    return collection;
}

Candy::collection Candy::ParserFuntion(Token::Tokens tokens, Candy::Token::Tokens reservedtokencollection, std::string ScopeTarget)
{

    Candy::collection collection;
    std::string _selectScopeTarget = "";
    std::string _lastKey = "";
    std::string _lastValue = "";
    bool _braketOpen = false;
    for (std::string token : tokens) // checking which scope are in. Like compile
    {
        if (token == ScopeTarget)
        {
            _selectScopeTarget = ScopeTarget;
            continue;
        }

        if (token == "{") // good
        {
            _braketOpen = true;
        }
        else if (token == "}") // good
        {
            _braketOpen = false;
            _selectScopeTarget = "";
        }
        else
        {
            if (_selectScopeTarget == ScopeTarget) // good
            {
                if (_lastKey.empty())
                {
                    std::vector<std::string>::iterator iter = std::find(reservedtokencollection.begin(), reservedtokencollection.end(), token);
                    if (iter != reservedtokencollection.end())
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
                    collection.value.push_back(Token::Value(_lastKey, _lastValue));
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

    return collection;
}