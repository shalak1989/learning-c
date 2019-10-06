#include <stdarg.h>
#include <stdio.h>

enum drink
{
    MUDSLIDE,
    FUZZY_NAVEL,
    MONKEY_GLAND,
    ZOMBIE
};

//in C ellpise after argument means the function should expect variable # of args
void print_ints(int args, ...)
{
    //this stores extra arguments passed to your function
    va_list ap;
    /*This says where the variable arguments start, this can be read as 
    "the variable args will start after the args parameter". It always needs to
    be the last "fixed" argument.
    */
    va_start(ap, args);

    //loop through all arguments, args contains the number of other arguments
    for (int i = 0; i < args; i++)
    {
        //va_arg takes two values, the va_list and the type of the next argument
        printf("argument: %i\n", va_arg(ap, int));
    }
    //You have to say va_end so C knows you are done.
    va_end(ap);
}

double price(enum drink d)
{
    switch (d)
    {
    case MUDSLIDE:
        return 6.79;
    case FUZZY_NAVEL:
        return 5.31;
    case MONKEY_GLAND:
        return 4.82;
    case ZOMBIE:
        return 5.89;
    default:
        return 0;
    }
}

double total(int args, ...)
{
    double total = 0;
    va_list argsPointer;

    va_start(argsPointer, args);

    for (int i = 0; i < args; i++)
    {
        enum drink d = va_arg(argsPointer, enum drink);
        total += price(d);
    }

    va_end(argsPointer);

    return total;
}

int main()
{
    //Remember first argument is number of variable args
    //print_ints(3, 79, 101, 32);
    printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));

    printf("Price is %.2f\n", total(2, MUDSLIDE, MUDSLIDE));
    printf("Price is %.2f\n", total(1, MONKEY_GLAND));

    return 0;
}