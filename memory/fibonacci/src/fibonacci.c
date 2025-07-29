#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

unsigned int * fib_jono(unsigned int n)
{
    int i;
    unsigned int *result = malloc(n*sizeof(unsigned int));

    result[0] = 0;
    result[1] = 1;

    for(i=2; i<n; i++)
    {
        result[i] = result[i-1] + result[i-2];
    }

    return result;
}

char *fib_jono_mj(unsigned int n)
{
    int i;
    int m;
    int val;
    char *result;
    int cap = 1;
    int used = 1;
    int a = 0;
    int b = 1;

    result = malloc(sizeof(char));
    *result = '\0';

    for(i=0; i<n; i++)
    {
        if(i == 0){val = a;}

        else if(i == 1){val = b;}

        else
        {
            val = a + b;
            a = b;
            b = val;
        }

        m = 3;
        if(val > 127){m++;} /*oletetaan vain keskiverto isoja lukuja*/

        if(i == 0){m = 1;}

        if(used + m > cap)  /*new malloc*/
        {
            while(used + m > cap){cap = 2*cap;}
            
            result = realloc(result, sizeof(char)*cap);
        }

        if(i == 0){sprintf(result, "%d", val);} /*put new value*/

        else{
            sprintf(result + strlen(result), ", %d", val);}

        if(i==0){used = used + m;}
        else{used = strlen(result);}
    }

    if(cap > used)
    {
        result = realloc(result, sizeof(char)*(used + 1)); /*muista \0*/
    }

    return result;
}