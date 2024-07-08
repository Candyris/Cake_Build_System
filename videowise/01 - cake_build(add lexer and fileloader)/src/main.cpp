#include <iostream>
#include "../include/cake.hpp"


void printTokens(Candy::Tokens tokens)
{
    std::cout <<"\n--------------Tokens Lists-------------------\n";
    for(auto token : tokens)
        std::cout<<token<<std::endl;
    std::cout<<"---------------------------end-------------------------\n";
}

int main(int argc, char** argv)
{
    std::cout<<"File Name : ";
    std::cout<<argv[1];

    std::string filecode = Candy::FileManger::loadStringFromfile(argv[1]);

    std::cout <<"\n--------------File context-------------------\n";
    std::cout<<filecode<<std::endl;
    std::cout<<"---------------------------end-------------------------\n";

    printTokens(Candy::Tokenizer(filecode.c_str()));
    
    std::cin.get();

    return 0;
}

// From Next video i will start the progress in this filesytem 😁😁