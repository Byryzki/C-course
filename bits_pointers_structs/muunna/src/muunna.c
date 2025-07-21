#include <stdio.h>
#include <math.h>
#include "muunna.h"

void muunnaTaulu(unsigned int s, double *arr, double (*tre)(double))
{
    int i;
    for(i=0; i<s; i++)
    {
        arr[i] = tre(arr[i]);
    }
}
