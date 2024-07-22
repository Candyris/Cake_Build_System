global
{
cxx : g++
std : 17
optimize : 3
define : NDEBUG
}
 compile
{
    include_dir(directory/include)
    srcfile(src/*.cpp)
    srcfile(src/*.c)
   }
linker
{
    link_dir(directory/lib)
    attach(glfw3)
    attach(opengl32)
    attach(gdi32)
    attach(kernel32)
}
output{
    outfile(bin/app);
}

