#include <stdio.h>

enum UnitOfMeasure
{
    COUNT,
    POUNDS,
    PINTS
};

union Quantity {
    short count;
    float weight;
    float volume;
};

struct FruitOrder
{
    const char *name;
    const char *country;
    union Quantity amount;
    enum UnitOfMeasure units;
};

void display(struct FruitOrder order)
{
    printf("This order contains ");

    if (order.units == PINTS)
    printf("%2.2f pints of %s\n", order.amount.volume, order.name);
    else if (order.units == POUNDS)
    printf("%2.2f lbs of %s\n", order.amount.weight, order.name);
    else
    printf("%i, %s\n", order.amount.count, order.name);
    
}

int main()
{
    /*designated initializers don't seem to have intellisense in VS code
        Consider setting members of structs in a different way:

        struct FruitOrder apples;
        apples.name = "apples";
        apples.country = "England";
        apples.amount.weight = 
        apples.units = 
    */
    struct FruitOrder apples = {"apples", "England", 
    .amount.count=144, COUNT};

    struct FruitOrder strawberries = {"strawberries", "Spain", 
    .amount.weight = 17.6, POUNDS};

    struct FruitOrder oj = {"orange juice", "U.S.A.", 
    .amount.volume=10.5, PINTS};

    display(apples);
    display(strawberries);
    display(oj);
    return 0;
}