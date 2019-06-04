#include <stdio.h>

struct Turtle
{
    char *name;
    int age;
};

void happy_birthday(struct Turtle *t)
{
    //(*t).age = (*t).age + 1;
    //alt syntax for above struct pointers
    t->age = t->age + 1;
    printf("Happy birthday %s! you are now %i years old!\n",
           (*t).name, (*t).age);
}

int main()
{
    struct Turtle bob;
    bob.age = 12;
    bob.name = "Bob";
    happy_birthday(&bob);
    printf("yep still %i", bob.age);
}