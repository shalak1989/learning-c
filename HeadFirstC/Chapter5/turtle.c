#include <stdio.h>

struct Turtle
{
    const char *name;
    const char *species;
    int age;
};

void happy_birthday(struct Turtle *t){
    (*t).age = (*t).age + 1;
    printf("Happy birthday %s! you are now %i years old!\n",
            (*t).name, (*t).age);
}

/*alternative syntax, t->age means "The age field in the struct 
that t points to*/

void happy_birthday_alt_syntax(struct Turtle *t){
    t->age = t->age + 1;
    printf("Happy birthday %s! you are now %i years old!\n",
            t->name, t->age);
}

int main()
{
    struct Turtle myrtle = {"Myrtle", "Leatherback sea turtle", 99};
    happy_birthday(&myrtle);
    printf("%s's age is now %i\n", myrtle.name, myrtle.age);
}