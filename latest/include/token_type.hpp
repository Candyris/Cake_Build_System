#pragma once
#include <string>
#include <vector>
namespace Candy
{
    namespace Token
    {
        using Tokens = std::vector<std::string>;
        using Value = std::pair<std::string, std::string>;
        /*struct Value
        {
            std::string key;
            std::string value;
            Value(std::string _key,std::string _value) : key(_key),value(_value){}
            Value getValue(){return {key,value};}*/
    };
};
