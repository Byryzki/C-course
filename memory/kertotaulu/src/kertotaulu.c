#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "kertotaulu.h"
/*
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
*/
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
    uint product;
    int cap;
    int m;
    int used;

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

    result = malloc(maxrow * sizeof(char *));
    result[maxrow-1] = '\0';

    for(i=0; i<maxrow; i++) /*Row wise*/
    {
        cap = 1;
        used = 1;

        result[i] = calloc(chars, sizeof(char));   /*allocate fresh memory for new row*/
        result[i][chars-1] = '\0';
        
        for(j=0; j<maxcol; j++)  /*col wise*/
        {
            product = (a+j-1)*(c+i-1);

            if(i==0 && j!=0){product = a+j-1;}
            
            if(j==0)
            {
                if(i==0){m = colwidths[j];}
                else{
                    m = colwidths[j] - (int)log10(c+i); product = c+i-1;}
            }
            else{
                m = 1 + colwidths[j] - (int)log10(product);}
            
            if(used + m > cap)
            {
                while(used + m > cap){cap = 2*cap;} /*more memory*/

                result[i] = realloc(result[i], sizeof(char)*cap);
            }

            if(j==0 && i==0){
                sprintf(result[i] + strlen(result[i]), "%*.s", colwidths[j], " ");}

            else if(j==0 && i!=0){
                sprintf(result[i] + strlen(result[i]), "%u", product);}

            else{
                sprintf(result[i] + strlen(result[i]), "%*u", colwidths[j]+1, product);}

            used = strlen(result[i]);
        }
        if(cap > used)  /*clean unneeded memory from array*/
        {
            result[i] = realloc(result[i], sizeof(char)*(used + 1));
        }


    }

    return result;
}
/*
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
    */