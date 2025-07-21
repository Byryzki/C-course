#include "vaihto.h"
#include <stdio.h>

void vaihda(int *a, int *b)
{
    int tmp1, tmp2;

    tmp1 = *a;
    tmp2 = *b;

    *a = tmp2;
    *b = tmp1;
}

void jarjesta(int *a, int *b, int *c)
{
    int i;
    int vara;
    int tmp[3];

    for(i=0; i<3; i++)
    {
        if(*a > *b)
        {
            vara = *b;
            *b = *a;
            *a = vara;
        }
        if(*b > *c)
        {
            vara = *c;
            *c = *b;
            *b = vara;
        }
    }
}