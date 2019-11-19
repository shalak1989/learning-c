/*

Static and dnyamic libraries: Hot-swappable code

In this chapter we will create our own libraries. This will include sharing code
at runtime with dynamic libraries.

When including your own libraries, remember angle brackets are for built in
standard headers. Angle brackets maeks the compiler look for them in standard
header directories.

To use your own use double quotes: #include "yourlibrary.h"

On linux STD lib stuff is usually stored /usr/local/include and usr/include.

You can use a full file path with your include statements or put them in a 
standard lib directory:

#include "/my_header_files/encrypt.h"

You can also tell the compiler where to find them with the -I option:

gcc -I/my_header_files test_code.c ... -o test_code

The above will tell the compiler to look in /my_header_files as well as std
directories.

You can share object files by putting them in a shared directory and using the
whole path:

gcc I/my_header_files test_code c /my_object_files/encrypt.o -o test_code

/my_object_files would be like a central store for your object files

You typically want an archive though. This is simply a whole bunch of object files
wrapped up into a single file. An archive contains .o files.

.a extension is for archive

you can use nm as a command to look inside .a files

ex: nm liblz32.a , you will see stuff like this:

depnbs00000.o:
00000000 i .idata$5
00000000 i .idata$6
         U __head_liblz32_a
00000000 I __imp__CopyLZFile@8
00000000 T _CopyLZFile@8

if you see T _main it means the object file has a main() function

The archive command (ar) will store a set of object files in an archive

ar -rcs libfile.a encrypt.o checksum.o

The r in -rcs means the .a file will be updated if it already exists. 
The c means the archive will
be made without feedback. The s tells ar to create an index at the start of the
a file.

Names are something like libsomething.a - this is the standard way of naming.
The names begin with lib because they are static libraries.

You can store your archives in several places:

1) You can put your .a file in a standard directory like usr/locallib.

2) Put it in another directory, you can always do something like /my_lib or 
c:/users/my_lib etc.

always name files lib<something>.a or the compiler will not find it easily

To compile you can use the -l switch:

gcc test_code.c -lhfsecurity -o test_code:

1) Remember to list your source file (test_code.c) before -l libraries
2) If you are using several archives use several -l options
3) hfsecurity tells the compiler to look for an archive called libhfsecurity.a
4) You may need a -I option after the -o depending on where headers are.
5) If your libraries are not in the standard directory you need to use -L instead
of -l:

gcc test_code.c -L/my_lib -lhfsecurity -o test_code


depnbs00005.o:
00000000 i .idata$5
00000000 i .idata$6
         U __head_liblz32_a
00000000 I __imp__LZDone@0
00000000 T _LZDone@0

T means "text" which means this is a function I think?

*/