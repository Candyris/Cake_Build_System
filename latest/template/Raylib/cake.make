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
    srcfile(main.cpp)
  }
linker
{
    link_dir(directory/lib)
    attach(raylib)
    attach(gdi32)
    attach(winmm)
}
output{
    outfile(bin/app);
}
