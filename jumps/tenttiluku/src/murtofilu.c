#include "murtofilu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void murtofilu(FILE *td, char *a, char *b)
{
    int i,j;
    int rivi, jono;
    char **taulukko;
    int cap;
    int used;
    char tmp[100];
    char red[100];

    rivi = atoi(a);
    jono = atoi(b);

    cap = 1;
    used = 1;

    taulukko = malloc((jono)*sizeof(char*));

    td = fopen("filu.txt", "wr+");
    if(td == NULL){perror("oho");}

    for(i=1; i<jono; i++)
    {
        taulukko[i] = malloc(sizeof(char));
        taulukko[i] = '\0';

        fprintf(td, "%*d", 4, rivi*i);
        
        for(j=0; j<rivi; j++)
        {
            fprintf(td, "%*d", 4, i*j*10);
            while(used + strlen(tmp) >= cap){
                cap = 2*cap; realloc(taulukko[i], cap);}
            used = cap;
        }
        fprintf(td, "\n");
    }

    fseek(td, 0, SEEK_SET);    /*crusial before reading*/

    fread(red, sizeof(char), 100, td);

    fclose(td);
}