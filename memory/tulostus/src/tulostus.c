#include <stdio.h>
#include <stdlib.h>
#include "tulostus.h"

void tulostaDblTaulu(double *taulu, size_t lkm, const char *taulNimi, int tarkkuus, const char *tiedNimi)
{
    int i;

    FILE *tied;
    tied = fopen(tiedNimi, "w");

    if(tied==NULL){exit(-1);}

    for(i=0; i<lkm; i++)
    {
        
        fprintf(tied, "%s[%d] = %.*f\n", taulNimi, i, tarkkuus, taulu[i]);
    }
    fclose(tied);
}