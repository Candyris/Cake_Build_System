#pragma once
#include <string>
#include <vector>
namespace Candy
{
    namespace Token{
    using Tokens = std::vector<std::string>;
    struct Value 
    {
        Value(std::string _key,std::string _value) : key(_key),value(_value){}
        std::string key;
        std::string value;
    };
    };
    
};