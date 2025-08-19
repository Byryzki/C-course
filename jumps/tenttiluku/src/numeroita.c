#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "numeroita.h"

char **numeroita(char *mj, ...)
{
    va_list args;
    double biggest;
    double smallest;
    
    char **buffer = malloc(2*sizeof(char*));
    char *smol = malloc(6*sizeof(char));
    char *big = malloc(6*sizeof(char));
    buffer[0] = smol;
    buffer[1] = big;


    va_start(args, mj);
    biggest = atof(mj);
    smallest = atof(mj);
    while( mj != NULL)
    {
        biggest = (biggest > atof(mj)) ? biggest : atof(mj);
        smallest = (smallest < atof(mj)) ? smallest : atof(mj);

        mj = va_arg(args, char *);
    }
    va_end(args);
    
    sprintf(smol, "%.3f", smallest);
    sprintf(big, "%.3f", biggest);

    return buffer;
}