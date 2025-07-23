#include "kolmijako.h"
#include "pikalaj.h"

#include <string.h>
#include <stdio.h>

void pikalajittele(int start, int end, int t[])
{
    int low = 0;
    int high = 0;
    int x = 0;
    int y = 0;
    IntPari ip = {0,0};
    
    if(start >= end){return;}

    if(end == start+1 || end == start+2){low = start; high = end;}
    else{low = end/4+1; high = 3*end/4;}

    ip = kolmijako(end-start+1, t+start, low, high, &x, &y);
    x = ip.x;
    y = ip.y;

    pikalajittele(start, x-1, t);   /*recursive ordering*/
    pikalajittele(x+1, y-1, t);
    pikalajittele(y+1, end, t);
}