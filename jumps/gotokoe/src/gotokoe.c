#include "gotokoe.h"

int max2D(int **t2d, int kork, int lev)
{
    int result;
    int x,y;

    result = -2147483648;
    x = 0;
    y = 0;


    base:
    if(t2d[y][x] > result && x == lev-1 && y == kork-1)
        goto y_lim;

    else if(t2d[y][x] <= result && x == lev-1 && y == kork-1)
        goto y_lim_same;
    
    else if(t2d[y][x] > result && x != lev-1)
        goto new_val;

    else if(t2d[y][x] > result && x == lev-1)
        goto x_lim; 

    else if(t2d[y][x] <= result && x != lev-1)
        goto same;

    else if(t2d[y][x] <= result && x == lev-1)
        goto x_lim_same; 
    

    new_val:
        result = t2d[y][x];    
        x++;
        goto base;

    x_lim:
        result = t2d[y][x];
        x = 0;    
        y++;
        goto base;

    y_lim:  /*reach end of table*/
        result = t2d[y][x];
        return result;

    same:
        x++;
        goto base;

    x_lim_same:
        x = 0;    
        y++;
        goto base;

    y_lim_same:  /*reach end of table*/
        return result;

    return 1;
}