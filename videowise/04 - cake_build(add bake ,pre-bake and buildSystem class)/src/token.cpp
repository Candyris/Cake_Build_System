#include "../include/token.hpp"
#include <string>
#include <vector>
#include <iostream>
Candy::Token::Tokens Candy::Tokenizer(const char *string) // also know lexer
{
   std::string input = string;
    std::vector<std::string>Tokens;
    std::string word = "";
    for (size_t i = 0 ; i < input.size(); i++)
    {
        switch(string[i])
        {
            // push back to the vector after completeing word
            
            case ' ' :
            if(!word.empty())
                Tokens.push_back(word);
            word = "";
            break;
            case '\n':
            if(!word.empty())
                Tokens.push_back(word);
            word = "";
            break;
            // --------------------------------------------Braces ------------------------------
            case '{' : //working 
            word += string[i]; 
            // pushing back string if anything behind braces
            if(!word.empty())
                Tokens.push_back(word.substr(0,word.length()-1  ));
            // pushing back braces
            Tokens.push_back(("{") );
            word = "";
            break;
            case '}' : // working 
            word += string[i];
            // pushing back string if anything behind braces
            if(!word.empty())
                Tokens.push_back(word.substr(0,word.length()-1  ));
            // pushing back braces
            Tokens.push_back(("}") );
            word = "";
            break;
            // ------------------------------------------End Brace--------------------------------------------
            // --------------------------------------------Barket ------------------------------
            case '(' : //working 
            word += string[i]; 
            // pushing back string if anything behind braces
            if(!word.empty())
                Tokens.push_back(word.substr(0,word.length()-1  ));
            // pushing back braces
            Tokens.push_back(("(") );
            word = "";
            break;
            case ')' : // working 
            word += string[i];
            // pushing back string if anything behind braces
            if(!word.empty())
                Tokens.push_back(word.substr(0,word.length()-1  ));
            // pushing back braces
            Tokens.push_back((")") );
            word = "";
            break;
            // -------------------------------------------- End Barket ------------------------------

            // add letter to the word 
            default:
            word += string[i];
            break;
        }
    }

    return Tokens;
}

// lets try this 