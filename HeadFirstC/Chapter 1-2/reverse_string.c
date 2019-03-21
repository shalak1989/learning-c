#include <stdio.h>
#include <string.h>

void print_reverse(char *s)
{
    size_t len = strlen(s);

    /*char *s will point to the first character in a char array then 
        you will add the length - 1 to get the last character.
      remember that char *s and char[] s would basically be the same thing
    */
    char *t = s + len - 1;

    //t starts by looking at the end of the array, you decrement down
    //since s is a pointer at index 0, code will stop after index 0

    while (t >= s)
    {
        printf("%c", *t);
        t = t - 1;
    }
    puts("");
}

int main(){
    char s[20];
    s[strlen(s) - 1] = '\0';
    puts("Enter a string to reverse up to 20 characters: ");
    scanf("%19s", s);
    print_reverse(s);
}