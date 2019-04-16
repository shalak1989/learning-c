#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* order of args will be the search word then the file output name.
remember argv[0] is the name of the actual program getting ran 

*/
int main(int argc, char *argv[])
{
    char line[80];
    if (argc != 6){
        fprintf(stderr, "You need to give 5 arguments\n");
        return 1;
    }
    //The example doesn't allow this to be a parameter, consider changing
    FILE *in;
    //fopen returns 0 if it cannot find the file, this ensures existence of file    
    /*Consider putting checks like this in a function
    * Also - check if STD library has a solution
    */
    if (!(in = fopen("gpsdata.csv", "r"))){
        fprintf(stderr, "Can't open the file.\n");
        //return a 1 for error and exit program
        return 1;
    }
    FILE *file1 = fopen(argv[2], "w");
    FILE *file2 = fopen(argv[4], "w");
    FILE *file3 = fopen(argv[5], "w");
    while (fscanf(in, "%79[^\n]\n", line) == 1)
    {
        if (strstr(line, argv[1]))
            fprintf(file1, "%s\n", line);
        else if (strstr(line, argv[3]))
            fprintf(file2, "%s\n", line);
        else
            fprintf(file3, "%s\n", line);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(in);
    return 0;
}