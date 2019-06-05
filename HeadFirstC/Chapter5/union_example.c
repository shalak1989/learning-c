union Quantity {
    short count;
    int big_count;
    float weight;
    float volume;
};
#include <stdio.h>

int main()
{
    /*
    IF union is going to store a value for the first field you 
    can use C89 notation
    */
    union Quantity q = {4}; //this means it will be count of 4

    //designated initializer sets a union field value by name:

    //set union for floating point weight value
    union Quantity q2 = {.weight = 1.5};

    //set with . notation
    union Quantity q3;

    q.volume = 3.7;

    /*REMEMBER: whichever way you set value there will only ever be
    one piece of data stored. The union just gives you a way of creating
    a variable that supports several different data types */
    //EX:

    /*
        With unions remmeber that the intent is for you to only use one
        field of the union. Setting different fields will corrupt the others.
        This is because a union only stores enough memory for the largest member.

        Once a member is set the integrity of all other members is in question.

        If you have multiple members with the same type (like 2 float fields)
        it seems like those will be safe.

        Further learning on unions required. For now though:

        If you use a union only set and use ONE member at a time. The 
        purpose of unions is to supply a flexible data structure that
        can set many different type fields. But only one can be set/valid
        at a time.

        This is because a union, regardless of the number of fields, only
        has a single place in memory.

        If this was built as a struct, there would be a separate space in
        memory for each type.

        If you only need one of many possible data types, use a union, otherwise
        stick with a struct.

        See useful stackoverflow:

        https://stackoverflow.com/questions/346536/difference-between-a-structure-and-a-union

        //Not all languages allow designated initializers, see
        HeadFirstC Location 3910 (kindle) in chapter 5
    
    */

    union Quantity e = {.count = 255}; //for short
    printf("short: %hi,\n int: %i,\n, float1: %f\n, float2: %f,\n\n",
           e.count, e.big_count, e.volume, e.weight);

    e.big_count = 256; //int
    printf("short: %hi,\n int: %i,\n, float1: %f\n, float2: %f,\n\n",
           e.count, e.big_count, e.volume, e.weight);

    e.weight = 2000.1235; //float, both float fields will show value
    printf("short: %hi,\n int: %i,\n, float1: %f\n, float2: %f,\n\n",
           e.count, e.big_count, e.volume, e.weight);
}