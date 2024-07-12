#pragma once 
const char* DEFAULT_CONTEXT = 
    " compile\n"
    "{\n"
    "    include_dir(include)\n"
    "    srcfile(main.cpp)\n"
    "   }\n"
    "linker\n"
    "{\n"
    "    link_dir(directory/lib)\n"
    "    attach(kernel32)\n"
    "}\n"
    "output{\n"
    "    outfile(app);\n"
    "}\n";