cls

del *.exe

windres Resource.rc -o Resource.o

g++ -mwindows -m64 -static -Wall -Wextra Buttons.cpp Resource.o -o Buttons.exe
