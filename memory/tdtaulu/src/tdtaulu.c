#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tdtaulu.h"

char *int2bin(int luku)
{
    int i;
    char *j;
    char *buffer;
    char *final;

    buffer = malloc(33*sizeof(char));
    buffer[32] = '\0';

    i = 0;
    while(i < 32)
    {
        if(pow(2, 32-i-1) <= luku)
        {
            buffer[i] = '1';
            luku = luku - pow(2, 32-i-1);
        }
        else{buffer[i] = '0';}

        i++;
    }

    i=0;    /*remove non significant zeros from front*/
    while(buffer[i] == '0'){i++;}
    final = malloc(33-i);
    final[32-i] = '\0';
    strcpy(final, buffer+i);
    free(buffer);

    return final;
}

TdTaulu * luoTdTaulu(unsigned int n, unsigned int alkioKoko, const char *tdNimi)
{
    int i;
    size_t koko;
    TdTaulu *uusitaulu;
    char *rimpsu;
    size_t written;

    uusitaulu = malloc(sizeof(TdTaulu));
    uusitaulu->n = n;
    uusitaulu->alkioKoko = alkioKoko;

    koko = strlen(tdNimi);
    uusitaulu->tdNimi = malloc(koko*sizeof(char));

    strcpy((char *)uusitaulu->tdNimi, tdNimi);

    uusitaulu->td = fopen(tdNimi, "w+b");
    if(uusitaulu->td == NULL)
    {
        perror("fopen failed");
        exit(EXIT_FAILURE);  // or handle the error
    }

    rimpsu = int2bin(n);
    written = fwrite(rimpsu, sizeof(char), strlen(rimpsu), uusitaulu->td);
    free(rimpsu);

    rimpsu = int2bin(alkioKoko);
    written = fwrite(rimpsu, sizeof(char), strlen(rimpsu), uusitaulu->td);
    free(rimpsu);

    for(i=0; i<n*alkioKoko; i++){written = fwrite("00000000", sizeof(char), 8, uusitaulu->td);}

    return uusitaulu;
}

TdTaulu * avaaTdTaulu(const char *tdNimi)
{

}

void vapautaTdTaulu(TdTaulu *tdt)
{

}

int tdtLue(TdTaulu *tdt, unsigned int i, unsigned int lkm, void *arvo)
{

}

int tdtKirj(TdTaulu *tdt, unsigned int i, unsigned int lkm, const void *arvo)
{

}