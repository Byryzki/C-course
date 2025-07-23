#include "tetris.h"
#include <stdio.h>


void paivita(char grid[20][10])
{
    int row;
    int sara;
    int col;
    int i;
    int full;
    char tmp[10] = {' '};
    char copy[20][10];

    for(row=0; row<20; row++)
    {
        for(col=0; col<10; col++)

        {
            copy[row][col] = grid[row][col];
        }
    }

    for(row=0; row<20; row++)
    {
        full = 1;
        for(col=0; col<10; col++)
        {
            if(grid[row][col] == ' '){
                full = 0; break;}
        }

        if(full)
        {
            sara = 0;
            while(sara <= row)
            {
                for(i=0; i<10; i++){grid[sara][i] = copy[sara-1][i];}
                sara++;
            }
            for(i=0; i<10; i++){grid[0][i] = ' ';}

            for(row=0; row<20; row++)   /*näytä*/
            {
                for(col=0; col<10; col++)
                {
                    printf("%c", copy[row][col]);
                }
                printf(" ");
                for(col=0; col<10; col++)
                {
                    printf("%c", grid[row][col]);
                }
                printf("\n");
            }
        }
    }
}