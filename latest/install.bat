echo app
g++ example/main.cpp -std=c++17 -I./directory/include -L./directory/lib -lglfw3 -mwindows -lopengl32 -o bin/app.exe
.\bin\app
