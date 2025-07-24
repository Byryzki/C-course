#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int * fib_jono(unsigned int n)
{
    int i;
    int tmp = 0;
    unsigned int *result = malloc(n*sizeof(unsigned int));

    result[0] = 0;
    result[1] = 1;

    for(i=2; i<n; i++)
    {
        result[i] = result[i-1] + result[i-2];
    }

    return result;
}