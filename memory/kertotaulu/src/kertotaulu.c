#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "kertotaulu.h"

Kertotaulu * luoKertotaulu(uint a, uint b, uint c, uint d)
{
    Kertotaulu *valmis = malloc(sizeof(Kertotaulu));
    int rivi;
    int sarake;
    uint rows = d-c+2;
    uint cols = b-a+2;
    
    valmis->a = a;
    valmis->b = b;
    valmis->c = c;
    valmis->d = d;
    
    valmis->kertotaulu = malloc(rows*sizeof(uint *));

    for(rivi=0; rivi<rows; rivi++)
    {
        valmis->kertotaulu[rivi] = malloc(cols*sizeof(uint));

        for(sarake=0; sarake<cols; sarake++)
        {
            if(sarake == 0 && rivi == 0){
                valmis->kertotaulu[rivi][sarake] = 1;}

            else if(sarake != 0 && rivi == 0){
                valmis->kertotaulu[rivi][sarake] = a+sarake-1;}

            else if(sarake == 0 && rivi != 0){
                valmis->kertotaulu[rivi][sarake] = c+rivi-1;}

            else{
                valmis->kertotaulu[rivi][sarake] = (a+sarake-1) * (c+rivi-1);}
        }
    }

    return valmis;
}

char ** luo_kertotaulu_mjt(uint a, uint b, uint c, uint d)
{
    int i;
    int j;
    int maxcol = b - a + 2;
    int maxrow = d - c + 2;
    char **result;
    int colwidths[maxcol];
    int spots = 0;
    int chars;
    int product;

    /*calculate col widths*/

    colwidths[0] = (int)log10(d)+1;
    spots = spots + colwidths[0];

    for(i=1; i<maxcol; i++)
    {
        colwidths[i] = (int)log10(d*(a+i-1))+1; /*how many spaces each number takes*/
        spots = spots + colwidths[i] + 1;
    }

    chars = 2*maxcol; /*row characters with \0*/

    /*construct the strings*/

    result = malloc(maxrow * sizeof(char));
    result[maxrow-1] = '\0';

    for(i=0; i<maxrow; i++) /*Row wise*/
    {
        result[i] = malloc(sizeof(char));   /*allocate memory for new row*/
        result[chars-1] = '\0';

        for(j=0; j<chars; j++)  /*col wise*/
        {
            if(j==0)
            {
                result[i] = realloc(result[i], strlen(result[i]) + colwidths[0] * sizeof(char));
                printf("row length: %zu \n", strlen(result[i]));
                sprintf(result[i], "%.*s", colwidths[0], ' ');  /*Kopioi Fibonaccin vastaava toteutus ja muokkaa. */
            }
            else
            {
                result[i] = realloc(result[i], 2 * sizeof(char));
                product = (a + j) * (c + i);
                sprintf(result[j], " %.*s", colwidths[j], (char)product);
            }
        }
    }

}

void tuhoaKertotaulu(Kertotaulu *kt)
{
    uint i;
    uint rows = kt->d-kt->c+2;

    if(kt == NULL){return;}

    for(i=0; i<rows; i++)
    {
        free(kt->kertotaulu[i]);
    }
    free(kt->kertotaulu);
    free(kt);
}