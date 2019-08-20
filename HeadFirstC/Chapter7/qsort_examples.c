#include <stdio.h>
#include <stdlib.h>

//void pointer can store a pointer to anything
int count = 0;

int compare_scores(const void *score_a, const void *score_b)
{
    /*
    (int*) is casting score_a as a int pointer, the * before (int*) is
    dereferencing the pointer to an int
    */
    int a = *(int *)score_a;
    int b = *(int *)score_b;

    /*
        for ints finding out which is greater is easy, just subtract
        If a > b this is positive, if a < b this is negative. if a and b
        are equal this is zero.
     */
    return a - b;
}

int compare_scores_desc(const void *score_a, const void *score_b)
{
    /*
    (int*) is casting score_a as a int pointer, the * before (int*) is
    dereferencing the pointer to an int
    */
    int a = *(int *)score_a;
    int b = *(int *)score_b;

    printf("a is %i\nb is %i\n", a, b);

    /*
        for ints finding out which is greater is easy, just subtract
        If a > b this is positive, if a < b this is negative. if a and b
        are equal this is zero.
     */
    return b - a;
}

/*
    You can even create structs to do more advanced sorting
 */
struct rectangle
{
    int width;
    int height;
};

/*
    Seems like it would be better to make sure that you ONLY use this 
    with an explicit array of rectangle structs instead of letting the 
    pointer assign themselves to width/height with no direction
 */
int compare_areas(const void *a, const void *b)
{

    //converts pointer to rectangle pointer
    struct rectangle *ra = (struct rectangle *)a;
    struct rectangle *rb = (struct rectangle *)b;
    int area_a = (ra->width * ra->height);
    int area_b = (rb->width * rb->height);
    count++;

    return area_a - area_b;
}

int compare_rectangle_areas(const void *a, const void *b)
{
    struct rectangle *ra = (struct rectangle *)a;
    struct rectangle *rb = (struct rectangle *)b;

    int area_a = (ra->width * ra->height);
    int area_b = (rb->width * rb->height);

    return area_a - area_b;
}

int main()
{
    /*
    /qsort() function compares pairs of values over and over again. If
    they are in the wrong order it will switch them

    the comparer function you pass should return three possible things:

    positive number - if the first value is greater than the second

    negative number -  if the first value is less than the second

    zero - if the two values are equal
    */

    int scores[] = {543, 323, 32, 554, 11, 3, 112};

    struct rectangle rectangles[] =
        {
            {
                .width = 8,
                .height = 2,
            },
            {.width = 5, .height = 2},
            {.width = 6, .height = 2},
        };

    int size = sizeof(scores) / sizeof(scores[0]);
    int sizeOfRectangles = sizeof(rectangles) / sizeof(rectangles[0]);

    qsort(scores, size, sizeof(scores[0]), compare_scores);

    qsort(rectangles, sizeOfRectangles, sizeof(rectangles[0]), compare_rectangle_areas);

    printf("Scores qsort\n");

    for (int i = 0; i < size; i++)
    {
        printf("%i\n", scores[i]);
    }

    printf("\n\n");
    printf("Rectangles\n");
    for (int i = 0; i < sizeOfRectangles; i++)
    {
        printf("height: %i and width: %i\n", rectangles[i].height, rectangles[i].width);
    }
}
