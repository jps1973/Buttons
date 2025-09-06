cls

del *.exe

g++ -mwindows -m64 -static -Wall -Wextra ^
 ^
 Buttons.cpp ^
 ^
 LinkedListClass.cpp ^
 ^
 ButtonWindow.cpp ^
 ^
 -o Buttons.exe -lole32 -luuid
