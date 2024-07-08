#include "../include/token.hpp"
#include <string>
#include <vector>
#include <iostream>
std::vector<std::string> Candy::Tokenizer(const char *string) // also know lexer
{
   std::string input = string;
    std::vector<std::string>Tokens;
    std::string word = "";
    for (size_t i = 0 ; i < input.size(); i++)
    {
        if (string[i] == ' ' || string[i] == '\n' )
        {
            Tokens.push_back(word);
            word = "";
        }
        else if (string[i] != '\n' && string[i] != ' ')
        {
            word += string[i];
        }
    }

    return Tokens;
}
