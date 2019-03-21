#include <stdio.h>
#include <string.h>

//first part declares array, this one is initilaized to [5][80]
//this is just a multi dimensional array
char tracks[][80] = {
    "I left my heart in Harvard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a Dork",
    "From here to maternity",
    "The girl from Iwo Jima",
};

void find_track(char search_for[])
{
    for (int i = 0; i < 5; i++)
    {
        //this searches each array index for the string "search_for"
        if (strstr(tracks[i], search_for)){
            //pretty sure %i is format string for number, and %s is for string
            //If you don't use the right ones you will get a Segmentation fault?
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

int main()
{
    char search_for[80];
    printf("Search for: ");
    scanf("%79s", search_for);
    //insert terminating character at final character array position 79
    search_for[strlen(search_for) - 1] = '\0';
    find_track(search_for);
    return 0;
}