#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch;
    for (int count = 0; count < argc; count++)
        puts(argv[count]);
    //This will loop through 
    while ((ch = getopt(argc, argv, "d:t")) != EOF)
        switch (ch)
        {
        case 'd':
            delivery = optarg;
            break;
        case 't':
            thick = 1;
            break;
        default:
            fprintf(stderr, "Unkonwn option: '%s'\n", optarg);
            return 1;
        }
    //not sure why we are subtracting here and not just setting it to index 0?
    /*Read more about unistd.h , it is a part of POSIX library which was 
    made to define common functions across all popular operating systems
    */
    argc -= optind;
    argv += optind;

    if (thick)
        puts("Thick crust.");

    if (delivery[0])
        printf("To be delviered %s.\n", delivery);

    puts("Ingredients:");
    for (count = 0; count < argc; count++)
        puts(argv[count]);
    return 0;
}