#include <iostream>
#include "../include/cake.hpp"
void printTokens(Candy::Token::Tokens tokens)
{
    std::cout << "\n--------------Tokens Lists-------------------\n";
    for (auto token : tokens)
        std::cout << token << ",";
    std::cout << std::endl;
    std::cout << "---------------------------end-------------------------\n";
}
void printCollection(Candy::collection collection,const char* collectionName)
{
    std::cout << "\n---------------------"<<collectionName<<"Collection Lists-------------------\n";
    collection.log();
    std::cout << "---------------------------  end  -------------------------\n";
}

int main(int argc, char **argv)
{
    std::cout << "File Name : ";
    std::cout << argv[1];

    // loading text from file
    std::string filecode = Candy::FileManger::loadStringFromfile(argv[1]);
    Candy::Token::Tokens tokens = Candy::Tokenizer(filecode.c_str()); // good 
    Candy::collection compileCollection = Candy::Parser(tokens, Candy::ReservedCollection::Compile,"compile");
    Candy::collection linkerCollection = Candy::Parser(tokens, Candy::ReservedCollection::Linker, "linker");
    Candy::collection outputCollection = Candy::Parser(tokens, Candy::ReservedCollection::Output, "output"); 

    printCollection(compileCollection,"compile");
    printCollection(linkerCollection,"linker");

    // BAD
    Candy::Scope scope;
    scope.genCompileCmd(compileCollection);
    scope.genLinkerCmd(linkerCollection);
    scope.genOutputCmd(outputCollection);
    std::cout<<scope.executeCmd("echo")<<std::endl; // good
    std::cin.get();

    return 0;
}
// make.cake default
// From Next video i will start the progress in this filesytem 😁😁