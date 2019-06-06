#include <stdio.h>

struct Island
{
    char *name;
    char *opens;
    char *closes;
    /*a pointer to another island, this is what makes this a 
    recursive structure*/

    struct Island *next;
};

void display(struct Island *start)
{
    struct Island *i = start;
    /*
        no initialization needed of i since we are iterating over 
        pointers.
    */
    for (; i != NULL; i = i->next)
    {
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
    }
}

int main()
{
    /*
    NULL is not built in but part of several libraries
    substituting for 0 could work but is dangerous in other scenarios

    NULL is simply #define NULL ((void *)0)
    stdio.h, stdlib.h etc would work
    */
   
    struct Island amity = {"Amity", "09:00", "17:00", NULL};
    struct Island craggy = {"Craggy", "09:00", "17:00", NULL};
    struct Island islaNublar = {"Isla Nublar", "09:00", "17:00", NULL};
    struct Island shutter = {"Shutter", "09:00", "17:00", NULL};

    //now you link them together
    amity.next = &craggy;
    craggy.next = &islaNublar;
    islaNublar.next = &shutter;

    //now you can easily change/add links
    struct Island skull = {"Skull", "09:00", "17:00", NULL};
    //this will mean islaNublar no longer goes directly to shutter
    islaNublar.next = &skull;
    //but now after going to skull you will go to shutter
    skull.next = &shutter;
    /*now we have added a new value into the LinkedList.
    Doing this with an array would involve making a new array,
    copying the data in up to the changed portion, and then inserting
    the new values.
    */
   display(&amity);
}