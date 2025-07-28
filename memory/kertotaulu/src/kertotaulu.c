#include <stdio.h>
#include <stdlib.h>
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