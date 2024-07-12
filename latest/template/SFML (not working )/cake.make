 compile
{
    include_dir(directory/include)
    srcfile(main.cpp)
   }
linker
{
    link_dir(directory/lib)

    attach(opengl32)
    attach(sfml-main)
    attach(sfml-graphics)
    attach(sfml-system)
    attach(sfml-window)
}
output{
    outfile(application/app);
}
