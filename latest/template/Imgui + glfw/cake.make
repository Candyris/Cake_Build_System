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
    include_dir(directory/include/IMGUI)
    srcfile(src/*.cpp)
    srcfile(directory/src/*.cpp)
   }
linker
{
    link_dir(directory/lib)
    attach(kernel32)
    attach(opengl32)
    attach(mingw32)
    attach(glfw3)
    attach(gdi32)
    attach(imm32)
    attach(kernel32)
}
output{
    outfile(bin/app);
}
