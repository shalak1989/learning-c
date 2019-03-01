#include <stdio.h>

int main()
{   
    char secret[3] = "bob";
    char ex[20];
    puts("enter something: ");
    scanf("%19s", ex);
    printf("Dear %s.", ex);
}