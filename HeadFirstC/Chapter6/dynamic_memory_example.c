#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Island
{
    char *name;
    char *opens;
    char *closes;
    struct Island *next;
};

//return type of Island struct pointer
struct Island *create(char *name)
{
    struct Island *i = malloc(sizeof(struct Island));
    /*
        tries to allocate enough memory to hold string + 1 for \0 char
        if it fails returns NULL
        then it copies the string to a new address and returns that
        address(pointer I believe);

        Not doing this means multiple structs could share the same address
        for their name field.

        If the struct had a name array instead of a char pointer this 
        would not be necessary. However an array requires you to know the
        exact size whereas a pointer doesn't.
    */
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void display(struct Island *start)
{
    struct Island *i = start;
    for (; i != NULL; i = i->next)
    {
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
    }
}

void release(struct Island *start)
{
    struct Island *i = start;
    struct Island *next = NULL;
    for (; i != NULL; i = next)
    {
        next = i->next;
        //first free the space in memory for the name which
        free(i->name);
        /*
        free address to struct only after freeing fields,
        not doing so may mean a memory leak on the name pointer
        */
        free(i);
    }
}

int main()
{
    struct Island *start = NULL;
    struct Island *i = NULL;
    struct Island *next = NULL;
    char name[80];
    /*
        keep reading until no more strings come in
        at the end of loop set i = to next pointer

    */
    for (; fgets(name, 80, stdin) != NULL; i = next)
    {
        //creates island
        next = create(name);
        //first time start is null so set it to the next pointer
        if (start == NULL)
            start = next;
        //make sure pointer isn't null before referencing a field
        if (i != NULL)
            i->next = next;
    }

    display(start);
    //release malloc memory
    release(start);
}