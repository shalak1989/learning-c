#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
    by simply adding a parameter that is a function pointer you can pass functions
    first return type, then name you want pointer to have, 
    then each parameter's type in the same ()
    (param1, param2)

    ex: int (*match)(char *, int)
*/
void find(char *ADS[], int size, int (*match)(char *))
{
    puts("Search results:");
    puts("-----------------------------");

    for (int i = 0; i < size; i++)
    {
        // for (int j = 0; j < strlen(ADS[i]); j++){
        //     /* Remember in C that you have made these strings not just character arrays
        //     //Like in other languages, strings in C are IMMUTABLE and this will cause
        //     a segmentation fault.

        //     Either you treat this like a non string array or you make a new array
        //     that contains upper case only
        //     */
        //     ADS[i][j] = toupper(ADS[i][j]);
        //}

        //old code before function param being passed - int(*match)(char*)
        // if (strstr(ADS[i], "sports") && !strstr(ADS[i], "bieber"))
        // {
        //     printf("%s\n", ADS[i]);
        // }

        /*
        could call the match function with (*match)(ADS[i]) but C knows
        what you mean by match(ADS[i])
        */
        if (match(ADS[i]))
        {
            printf("%s\n", ADS[i]);
        }
    }
}

int sports_no_bieber(char *s)
{
    return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_workout(char *s)
{
    return strstr(s, "sports") || strstr(s, "workout");
}

int ns_theater(char *s)
{
    return strstr(s, "NS") && strstr(s, "theater");
}

int arts_theater_or_dining(char *s)
{
    return strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dining");
}

int main()
{
    char *ADS[] = {
        "William: SBM GSOH likes sports, TV, dining",
        "Matt: SWM NS likes art, movies, theater",
        "Luis: SLM ND likes books, theater, art",
        "Mike: DWM DS likes trucks, sports and bieber",
        "Peter: SAM likes chess, working out and art",
        "Josh: SJM likes sports, movies and theater",
        "Jed: DBM likes theater, books and dining",
    };

    int adsSize = sizeof(ADS) / sizeof(ADS[0]);

    /* 
    Do not perform sizeof on array parameters. This will cause you to get
    the size of the pointer to the first element of the array NOT the whole
    array itself.

    Right before the function call do sizeof(Array) / sizeof(Array[0]). This
    will take the size of the whole array in bytes and divide it by a single 
    members size, giving you a true size.

    ALSO NOTE: It sizeof returns an unsigned int. You can do an implicit conversion
    by assigning this unsigned int to an int however it could truncate extremely
    large values. 

    This is likely not a problem but you may want to build in check functions.
    These functions could determine if the size of the unsigned int will 
    be too big for the int and cause truncation.

    Always make your array functions take a size parameter to avoid 
    this bug
    */

    //old call before function added as param
    //find(ADS, adsSize);
    find(ADS, adsSize, sports_no_bieber);
    find(ADS, adsSize, sports_or_workout);
    find(ADS, adsSize, ns_theater);
    find(ADS, adsSize, arts_theater_or_dining);
}
