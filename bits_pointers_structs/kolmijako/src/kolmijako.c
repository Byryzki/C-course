#include <stdio.h>
#include <stdlib.h>
#include "kolmijako.h"
#include <string.h>

void muunna(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

IntPari kolmijako(unsigned int n, int t[], int pivot1, int pivot2, int *p1, int *p2)    /*itse algoritmi O(n) */
{
    int i;
    IntPari ip;

    int y = 0;
    int yla[1000] = {0};
    int k = 0;
    int keski[1000] = {0};
    int a = 0;
    int ala[1000] = {0};

    int tmpa;
    int tmpy;

    int low = (pivot1 < pivot2) ? pivot1 : pivot2;  /*pivot indexit arvojarjestykseen*/
    int high = (pivot1 > pivot2) ? pivot1 : pivot2;

    if(t[low] > t[high]){muunna(&t[low], &t[high]);}  /*pivot arvojarjestykseen*/

    if(n == 2)  /*only 2 values to sort*/
    {
        t[pivot1] = (t[pivot1] < t[pivot2]) ? t[pivot1]:t[pivot2]; ala[pivot1] = t[pivot1];
        t[pivot2] = (t[pivot1] > t[pivot2]) ? t[pivot1]:t[pivot2]; yla[pivot1] = t[pivot2];

        ip.x = low;
        ip.y = high;
        return ip;
    }

    tmpa = t[low];
    tmpy = t[high];

    for(i=0; i<n; i++)  /*ryhmittely*/
    {
        if(t[i] < t[low]){ala[a] = t[i]; a++;}
        else if(t[i] > t[low] && t[i] < t[high]){keski[k] = t[i]; k++;}
        else if(t[i] > t[high]){yla[y] = t[i]; y++;}
    }

    i=0;
    while(i<a){t[i] = ala[i]; i++;}
    low = i;
    t[i] = tmpa;
    i++;
    while(i-a-1<k){t[i] = keski[i-a-1]; i++;}
    high = i;
    t[i] = tmpy;
    i++;
    while(i-a-k-2<y){t[i] = yla[i-a-k-2]; i++;}

    for(i=0; i<n; i++){printf("%d ", t[i]);} printf("\n");

    *p1 = low;
    *p2 = high;

    ip.x = low;
    ip.y = high;

    return ip;
}