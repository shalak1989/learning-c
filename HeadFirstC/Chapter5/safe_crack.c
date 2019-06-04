#include <stdio.h>

//saw advice to stop typedefing every struct, leaving this as example

// typedef struct{
//     const char *description;
//     float value;

// }swag;

// typedef struct {
//     swag *swag;
//     const char *sequence;
// } combination;

// typedef struct {
//     combination numbers;
//     const char *make;
// };

struct swag
{
    const char *description;
    float value;
};

struct combination
{
    struct swag *swag;
    const char *sequence;
};

struct safe
{
    struct combination numbers;
    const char *make;
};

int main()
{
    struct swag gold = {"GOLD!", 1000000.0};
    struct combination numbers = {&gold, "6502"};
    struct safe safe = {numbers, "RAMACON250"};
    printf("%s", safe.numbers.swag->description);
}