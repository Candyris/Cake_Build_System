#pragma once 
#include "token_type.hpp"
#include <vector>
#include <string>

namespace Candy
{
    using Tokens = std::vector<std::string>;
    
    Tokens Tokenizer(const char* string);
}
