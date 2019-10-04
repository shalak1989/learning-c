#include <stdio.h>

enum response_type
{
    DUMP,
    SECOND_CHANCE,
    MARRIAGE
};

struct Response
{
    char *name;
    enum response_type type;
};

void dump(struct Response r)
{
    printf("Dear %s,\n", r.name);
    puts("Unfortunately your last date contacted us to");
    puts("say that they will not be seeing you again\n");
}

void second_chance(struct Response r)
{
    printf("Dear %s,\n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP.\n");
}

void marriage(struct Response r)
{
    printf("Dear %s,\n", r.name);
    puts("Congratulations! Your last date has contacted");
    puts("us with a proposal of marriage.\n");
}

void (*replies[])(struct Response) = {dump, second_chance, marriage};

int main()
{

    struct Response r[] = {
        {"Mike", DUMP}, {"Luis", SECOND_CHANCE}, {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}};

    int sizeOfResponses = sizeof(r) / sizeof(r[0]);
    for (int i = 0; i < sizeOfResponses; i++)
    {
        replies[r[i].type](r[i]);
        //alternatively (*replies[r[i].type])(r[i]);
        //alternatively (replies[r[i].type])(r[i]);
    }

    //See Chapter 7, old way below, new way using function pointer array above.

    // struct Response r[] = {
    //     {"Mike", DUMP}, {"Luis", SECOND_CHANCE}, {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}};

    // int sizeOfResponses = sizeof(r) / sizeof(r[0]);
    // for (int i = 0; i < sizeOfResponses; i++)
    // {
    //     switch (r[i].type)
    //     {
    //         case DUMP:
    //             dump(r[i]);
    //             break;
    //         case SECOND_CHANCE:
    //             second_chance(r[i]);
    //             break;
    //         default:
    //             marriage(r[i]);
    //     }
    // }
    return 0;
}