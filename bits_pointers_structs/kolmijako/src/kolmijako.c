#include <stdio.h>
#include "kolmijako.h"

IntPari kolmijako(unsigned int n, int t[], int pivot1, int pivot2, int *p1, int *p2)
{
    int i;
    int less1 = 0;
    int less2 = 0;
    int tmp;
    IntPari ip;

    if(t[pivot1] > t[pivot2])
    {
        tmp = pivot1;
        pivot1 = pivot2;
        pivot2 = tmp;
    }

    for(i=0; i<n; i++)
    {
        if(t[i] < t[pivot1])
        {
            tmp = t[i];
            t[i] = t[pivot1];
            t[pivot1] = tmp;

            if(pivot1 == less1){pivot1 = i;}
            if(pivot2 == less1){pivot2 = i;}

            less1 = i;
        }
    }
    less1++;

    tmp = t[less1];
    t[less1] = t[pivot1];
    t[pivot1] = tmp;

    if(pivot2 == less1)
    {
        /*?*/
    }

    less2 = less1 + 1;
    for(i=less2; i<n; i++)
    {
        if(t[i] < t[pivot2])
        {
            tmp = t[less2];
            t[less2] = t[pivot2];
            t[pivot2] = tmp;

            less2 = i;
        }

        if(pivot2 == less2){pivot2 = i;}
    }
    less2++;

    tmp = t[less2];
    t[less2] = t[pivot2];
    t[pivot2] = tmp;

    *p1 = less1;
    *p2 = less2;

    ip.x = less1;
    ip.y = less2;

    return ip;
}