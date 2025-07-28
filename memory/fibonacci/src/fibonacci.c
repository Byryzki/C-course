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

char * fib_jono_mj(unsigned int n)
{
    int i;
    int m;
    int val;
    char *result;
    char *tmp_ptr;
    int cap = 1;
    int used = 1;

    result = malloc(sizeof(char));
    result = '\0';

    for(i=0; i<n; i++)
    {
        if(i == 0){val = 0;}

        else if(i == 1){val = 1;}

        else{val = result[-1] + result[-2];}

        m = 3;
        if(val > 127){m++;} /*oletetaan vain keskiverto isoja lukuja*/

        if(i == 0){m = 1;}

        if(used + m > cap)
        {
            while(used + m > cap){cap = 2*cap;}
            
            tmp_ptr = realloc(result, sizeof(char)*cap);
            result = tmp_ptr;
        }

        if(i == 0){sprintf(result, "%d", val);}

        else{sprintf(result, ", %d", val);}

        used = used + m;
    }

    if(cap > used)
    {
        tmp_ptr = realloc(result, sizeof(char)*used);
        result = tmp_ptr;
    }

    return result;
}