 compile
{
    include_dir(directory/include)
    srcfile(main.cpp)
   }
linker
{
    link_dir(directory/lib)
    attach(mingw32)
    attach(SDL2main)
    attach(SDL2)

}
output{
    outfile(bin/app);
}