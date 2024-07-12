#include <iostream>
#include "cake.hpp"
#include "../include/default.hpp"

int main(int argc, char **argv)
{
    std::cout << "INPUT : " << argv[1] << "\n";
    std::string mode = argv[1];
    if (mode == "pre-bake")
    {
        std::cout << "[PRE_BUILD]\n";
        Candy::FileManger::createFileWithContext(CAKEBUILD_FILEPATH, DEFAULT_CONTEXT);
    }
    else if (mode == "bake")
    {
        std::cout << "[BUILD]\n";
        std::string mode2 = argv[2];
        if (mode2 == "app")
        {
            Candy::BuildSystem buildsystem;
            buildsystem.LoadFile(CAKEBUILD_FILEPATH);
            buildsystem.generateToken();
            buildsystem.generateCommand();
            buildsystem.runCommand("g++"," -mwindows");
            std::cout << "[APPLICATION BAKED]\n";
        }
        else if (mode2 == "console")
        {
            Candy::BuildSystem buildsystem;
            buildsystem.LoadFile(CAKEBUILD_FILEPATH);
            buildsystem.generateToken();
            buildsystem.generateCommand();
            buildsystem.runCommand("g++");
            std::cout << "[CONSOLE BAKED]\n";
        }
    }
    else
    {
        std::cout << "Wrong !!\n"
                  << std::endl;
    }
    std::cin.get();
}
// make.cake default
// From Next video i will start the progress in this filesytem 😁😁
