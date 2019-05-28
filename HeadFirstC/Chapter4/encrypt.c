#include "encrypt.h"

/*This will perform encryption */
void encrypt(char *message)
{
    while (*message){
        *message = *message ^ 31;
        message++;
    }
}