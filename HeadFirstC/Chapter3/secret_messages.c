#include <stdio.h>

int main()
{
    /*
        Run with ./secret_messages.exe < secret.txt > messages1.txt 2> message2.txt
        This the 2> message2.txt will redirect the stderr messages to the 
        message2.txt file.

        The first time i % 2 runs it will be 1 and 1 % 2 = 1. 

        The next time it runs 2 % 2 = 0 which means it will print to the stderr

    */
    char word[10];
    int i = 0;
    while (scanf("%9s", word) == 1)
    {
        i = i + 1;
        if (i % 2)
            fprintf(stdout, "%s\n", word);
        else
            fprintf(stderr, "%s\n", word);
    }
    return 0;
}
