#include "../include/build_system.hpp"

#pragma region helper
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
#pragma endregion
#pragma region ReservedToken 
namespace Candy::ReservedCollection
{
    Token::Tokens Compile{
        "include_dir",
        "srcfile"};
    Token::Tokens Linker{
        "link_dir",
        "attach"};
    Token::Tokens Output{
        "outfile"};
};
#pragma endregion

void Candy::BuildSystem::LoadFile(const char* filepath)
{
    m_Filecode = Candy::FileManger::loadStringFromfile(filepath); //working 
    //std::cout<<"file code :"<<m_Filecode<<std::endl;
}

void Candy::BuildSystem::generateToken()
{
    Candy::Token::Tokens tokens = Candy::Tokenizer(m_Filecode.c_str()); // working 
    m_CompileCollection = Candy::Parser(tokens, ReservedCollection::Compile,"compile"); // working
    m_LinkerCollection = Candy::Parser(tokens, ReservedCollection::Linker, "linker"); // working 
    m_OutputCollection = Candy::Parser(tokens, ReservedCollection::Output, "output"); // working

    // print collections
    // printCollection(compileCollection, "compile ");
    // printCollection(linkerCollection, "linker ");
    // printCollection(outputCollection, "output ");

}

void Candy::BuildSystem::generateCommand()
{
    Candy::Scope scope;
    
    scope.genCompileCmd(m_CompileCollection); // working
    scope.genLinkerCmd (m_LinkerCollection); // working
    scope.genOutputCmd (m_OutputCollection); // working 
    m_CommandPrompt = scope.getCmd(); // working
    std::cout<<"cmd generated: "<< scope.getCmd()<<"end\n";
}

void Candy::BuildSystem::runCommand(const char *CompileName,const char *link )
{
    std::cout<<" cmd " << m_CommandPrompt<<"\n";
    std::string _name = CompileName;
    std::string _link = link;
    system((_name + m_CommandPrompt + _link).c_str());
    std::cout<<"final"<<(_name + m_CommandPrompt + _link).c_str()<<std::endl;
}