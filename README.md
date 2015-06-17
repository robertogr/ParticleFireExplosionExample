
-Using **MinGW** c++ compiler
-We need to include in system variable path: **C:\MinGW\bin;C:\MinGW\msys\1.0\bin;** 
-Headers and libraries are in SLD for MinGW in: i686-w64-mingw32 (32bits...i know, name is confusing)
-/SDL2 /include inside i686-w64-mingw32 and /lib must be copy ti C:\MinGW\include and c:\MinGW\lib. I couldn't get it work if not.
-In project properties -> C/C++ Build -> Settings -> C++ Compiler -> Includes (we need here SDL include directory containing headers)
-In project properties -> C/C++ Build -> Settings -> MinGW C++ Linker -> Libraries (Where is /lib of the SDL? )
Add (order sensitive):
    -mingw32
    -SDL2main
    -SDL2
-main signature must be: int main(int argc, char* argv[]). if it is not, It'll be a conflict .

created with http://prose.io
