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
    Token::Tokens global{
        "cxx",
        "std",
        "optimize",
        "define"};
};
#pragma endregion

void Candy::BuildSystem::LoadFile(const char* filepath)
{
    m_Filecode = Candy::FileManger::loadStringFromfile(filepath); 
    //std::cout<<"file code :"<<m_Filecode<<std::endl;
}

void Candy::BuildSystem::generateToken() 
{
    Candy::Token::Tokens tokens = Candy::Tokenizer(m_Filecode.c_str()); 

    m_GlobalCollection = Candy::ParserKeyword(tokens,ReservedCollection::global,"global");
    m_CompileCollection = Candy::ParserFuntion(tokens, ReservedCollection::Compile,"compile"); 
    m_LinkerCollection = Candy::ParserFuntion(tokens, ReservedCollection::Linker, "linker"); 
    m_OutputCollection = Candy::ParserFuntion(tokens, ReservedCollection::Output, "output"); 

    // print collections
    // printCollection(m_GlobalCollection,"global");
    // printCollection(m_CompileCollection, "compile ");
    // printCollection(m_LinkerCollection, "linker ");
    // printCollection(m_OutputCollection, "output ");
}

void Candy::BuildSystem::generateCommand() 
{
    Candy::Scope scope;
    scope.genGlobalCmd(m_GlobalCollection); 
    scope.genCompileCmd(m_CompileCollection); 
    scope.genLinkerCmd (m_LinkerCollection); 
    scope.genOutputCmd (m_OutputCollection); 
    m_CommandPrompt = scope.getCmd(); 
}

void Candy::BuildSystem::runCommand(const char *link )
{
    std::string _link = link;
    std::cout<<"[CODE GERNERATED] : ";
    std::cout<<m_CommandPrompt + _link<<std::endl;
    system((m_CommandPrompt + _link).c_str());
}