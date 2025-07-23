#include "kolmijako.h"
#include "pikalaj.h"

#include <string.h>
#include <stdio.h>

void pikalajittele(int start, int end, int t[])
{
    int i;
    int low;
    int high;
    int x;
    int y;
    IntPari ip = {0,0};

    printf("start ja end: %d %d\n", start, end);
    
    if(start >= end){
        return;}

    if(end == start+1 || end == start+2){low = start; high = end;}
    else{low = end/4+1; high = 3*end/4;}

    printf("low ja high: %d %d\n", low, high);

    ip = kolmijako(end-start+1, t+start, low, high, &x, &y);
    x = ip.x;
    y = ip.y;
    printf("x ja y: %d %d\n", x, y);

    pikalajittele(start, x-1, t);   /*recursive ordering*/
    pikalajittele(x+1, y-1, t);
    pikalajittele(y+1, end, t);
}