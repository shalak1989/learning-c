#include <stdio.h>
#include "my_includes/hfcal.h"

int main()
{
    display_calories(115.2, 11.3, 0.79);
    return 0;
}

/*
    To compile:

    1) start by making object file hfcal.o. 

    gcc -I/header_files -c hfcal.c -o hfcal.o -- 
    -c means create object file but don't link it

    2) Create object file called ellpitical.o from the ellpitical.c 
    test program

    gcc -I/header_files -c ellpitical.c -o elliptical.o

    3) Now you need to create an archive library from hfcal.o and store it in libs

    ar -res /libs/libhfcal.a hfcal.o

    A lot of people put this in MinGW's libs location

    4) Finally create the elliptical executable using elliptical.o and the hfcal
    archive

    gcc elliptical -L/libs (tells gcc where libraries are stored) -lhfcal -o elliptical

    -L/my_lib tells gcc where libraries are stored
    elliptical.o you are building the program using elliptical.o and the library

    -lhfcal tells the compiler to look for libhfcal.a 

    -- For your computer since you aren't using default lib directory:

 gcc elliptical.o -L/C:/repos/learning-c/HeadFirstC/Chapter8/my_lib -lhfcal -o elliptical

*/