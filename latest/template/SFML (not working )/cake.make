global
{
cxx : g++
std : 17
optimize : 3
define : SFML_STATIC
}
 compile
{
    include_dir(directory/include)
    srcfile(main.cpp)
   }
linker
{
    link_dir(directory/lib)

    attach(opengl32)
    attach(sfml-graphics)
    attach(sfml-window)
    attach(sfml-system)
}
output{
    outfile(application/app);
}
