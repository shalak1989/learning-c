#include <stdio.h>

union Quantity {
    short count;
    int big_count;
    float weight;
    float volume;
};

struct Fruit_Order
{
    const char *name;
    const char *country;
    union Quantity amount;
};

union Lemon_Lime {
    float lemon;
    int lime_pieces;
};

struct Margarita {
    float tequila;
    float cointreau;
    union Lemon_Lime citrus;
};

int main()
{
    struct Fruit_Order apples = {"apples", "England", 
    .amount.weight = 4.2};

    printf("This order contains %2.2f lbs of %s\n", 
    apples.amount.weight, apples.name);

    struct Margarita m = {.tequila = 2.0, .cointreau = 1.0, 
    .citrus.lemon = 2};

    struct Margarita m2; 
    m2.tequila = 2; 
    m2.cointreau = 1; 
    m2.citrus.lime_pieces = 2;
    //in C whitespace between strings is concatenation see:
    //https://stackoverflow.com/questions/1752079/in-c-can-a-long-printf-statement-be-broken-up-into-multiple-lines
    printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n"
    "%i pieces of lime\n\n", m2.tequila, m2.cointreau, m2.citrus);

     printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n"
    "%f units of lemon\n", m.tequila, m.cointreau, m.citrus.lemon);
}