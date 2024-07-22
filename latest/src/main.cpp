#include <iostream>
#include "cake.hpp"
#include "../include/default.hpp"

int main(int argc, char **argv)
{
    std::cout << "[INPUT] : " << argv[1] << "\n\n";
    std::string mode = argv[1];
    if (mode == "pre-bake")
    {
        std::cout << "[PRE_BAKE]\n";
        Candy::FileManger::createFileWithContext(CAKEBUILD_FILEPATH, DEFAULT_CONTEXT);
    }
    else if (mode == "bake")
    {
        std::cout << "[BAKE]\n";
        std::string mode2 = argv[2];
        if (mode2 == "app")
        {
            Candy::BuildSystem buildsystem;
            buildsystem.LoadFile(CAKEBUILD_FILEPATH);
            buildsystem.generateToken();
            buildsystem.generateCommand();
            buildsystem.runCommand(" -mwindows");
            std::cout << "[APPLICATION BAKED]\n";
        }
        else if (mode2 == "console")
        {
            
                Candy::BuildSystem buildsystem;
                buildsystem.LoadFile(CAKEBUILD_FILEPATH);
                buildsystem.generateToken();
                buildsystem.generateCommand(); // failed
                buildsystem.runCommand("");

                std::cout << "[CONSOLE BAKED]\n";
            
        }
        else if (mode2 == "winmain")
        {

            Candy::BuildSystem buildsystem;
            buildsystem.LoadFile(CAKEBUILD_FILEPATH);
            buildsystem.generateToken();
            buildsystem.generateCommand();
            buildsystem.runCommand("-mwindows -municode");

            std::cout << "[WINMAIN APP BAKED]\n";
        }
    }
    else
    {
        std::cout << "Wrong Input !!"<<std::endl;
    }
    std::cout<<std::endl;
}