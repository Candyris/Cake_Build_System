#include "../include/token_type.hpp"
#include "../include/paser.hpp"
#include <map>
#include <algorithm>

Candy::collection Candy::Parser(Token::Tokens tokens, Candy::Token::Tokens reservedtokencollection, std::string ScopeTarget)
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