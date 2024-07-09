#include <iostream>
#include "../include/cake.hpp"


void printTokens(Candy::Token::Tokens tokens)
{
    std::cout <<"\n--------------Tokens Lists-------------------\n";
    for(auto token : tokens)
        std::cout<<token<<",";
    std::cout<<std::endl;
    std::cout<<"---------------------------end-------------------------\n";
}

int main(int argc, char** argv)
{
    std::cout<<"File Name : ";
    std::cout<<argv[1];

    // loading text from file 
    std::string filecode = Candy::FileManger::loadStringFromfile(argv[1]); 

    printTokens(Candy::Tokenizer(filecode.c_str()));

    Candy::Parser paser(Candy::Tokenizer(filecode.c_str()));
    paser.printCompileCollection();
    
    std::cin.get();

    return 0;
}

// From Next video i will start the progress in this filesytem 😁😁