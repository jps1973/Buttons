cls

del *.exe

g++ -mwindows -m64 -static -Wall -Wextra ^
 ^
 Buttons.cpp ^
 ^
 ButtonWindow.cpp ^
 ^
 -o Buttons.exe
