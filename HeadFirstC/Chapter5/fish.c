#include <stdio.h>

struct Exercise {
    const char *description;
    float duration;
};

struct Meal {
    const char *ingredients;
    float weight;
};

struct Preferences
{
    struct Meal food;
    struct Exercise exercise;
};

struct Fish
{
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct Preferences care;
};

void catalog(struct Fish fish)
{
    printf("%s is a %s with %i teeth. He is %i\n years old.\n",
           fish.name, fish.species, fish.teeth, fish.age);
}

void label(struct Fish a){
    printf("Name:%s\nSpecies:%s\n %i years old, %i teeth\n",
    a.name, a.species, a.teeth, a.age);
    printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours\n"
    , a.care.food.weight, a.care.food.ingredients, a.care.exercise.description
    , a.care.exercise.duration);
}

int main()
{
    struct Fish snappy = {"Snappy", "Piranha", 69, 4, 
    {{"meat", 0.2}, {"swim in the jacuzzi", 7.5}}};

    label(snappy);
    // struct Fish snappy = {"Snappy", "Piranha", 69, 4, {"Meat", 7.5}};
    // struct Fish gnasher = snappy;
    
    // catalog(snappy);
    // catalog(gnasher);
    // printf("Snappy likes to eat %s\n", snappy.care.food);
    // printf("Snappy likes to exercise for %f hours\n", snappy.care.exercise.duration);

    return 0;
}