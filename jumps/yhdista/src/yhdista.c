#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "yhdista.h"

char *yhdista(const char *mj, ...)
{   
    va_list args;
    const char *arg;
    char *result;

    va_start(args, mj);

    result = malloc(1024);
    if (!result) return NULL;

    strcpy(result, mj);
    
    while((arg = va_arg(args, const char *)) != NULL)
    {
        strcat(result, arg);
    }

    va_end(args);
    return result;
}