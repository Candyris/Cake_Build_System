#pragma once
#include "token.hpp"
namespace Candy::ReservedCollection
{
    Candy::Token::Tokens Compile{
        "include_dir",
        "srcfile"};
    Candy::Token::Tokens Linker{
        "link_dir",
        "attach"};
    Candy::Token::Tokens Output{
        "outfile"};
};