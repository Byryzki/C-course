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
    int mitta;
    size_t koko;
    TdTaulu *uusitaulu;
    unsigned char nolla;
    size_t written;

    uusitaulu = malloc(sizeof(TdTaulu));
    uusitaulu->n = n;
    uusitaulu->alkioKoko = alkioKoko;

    koko = strlen(tdNimi);
    uusitaulu->tdNimi = malloc(koko*sizeof(char));

    strcpy((char *)uusitaulu->tdNimi, tdNimi);

    uusitaulu->td = fopen(tdNimi, "wb+");
    if(uusitaulu->td == NULL)
    {
        perror("fopen failed");
        return(NULL);
    }

    written = fwrite(&n, sizeof(unsigned int), 1, uusitaulu->td);
    if(written != 1)
    {
        perror("fwrite failed");
        return(NULL);
    }

    written = fwrite(&alkioKoko, sizeof(char), 1, uusitaulu->td);
    if(written != 1)
    {
        perror("fwrite failed");
        return(NULL);
    }

    nolla = 0;
    for(i=0; i<n*alkioKoko; i++){written = fwrite(&nolla, sizeof(char), 1, uusitaulu->td);}
    if(written != 1)
    {
        perror("fwrite failed");
        return(NULL);
    }

    return uusitaulu;
}

TdTaulu * avaaTdTaulu(const char *tdNimi)
{
    int status;
    size_t koko;
    TdTaulu *uusitaulu;
    unsigned int buffer[2];

    uusitaulu = malloc(sizeof(TdTaulu));

    koko = strlen(tdNimi);
    uusitaulu->tdNimi = malloc(koko*sizeof(char));

    strcpy((char *)uusitaulu->tdNimi, tdNimi);

    uusitaulu->td = fopen(tdNimi, "rb+");
    if(uusitaulu->td == NULL)
    {
        perror("fopen failed");
        return(NULL);
    }

    status = fread(buffer, sizeof(unsigned int), 2, uusitaulu->td);
    if(status != 2)
    {
        perror("fread failed");
        return(NULL);
    }

    uusitaulu->n = buffer[0];
    uusitaulu->alkioKoko = buffer[1];

    return uusitaulu;
}

void vapautaTdTaulu(TdTaulu *tdt)
{
    fclose(tdt->td);
    
    free((char *)tdt->tdNimi);
    free(tdt);  /*tarviiko vapauttaa muita jäseniä?*/
}

int tdtLue(TdTaulu *tdt, unsigned int i, unsigned int lkm, void *arvo)
{
    int status;

    status = fseek(tdt->td, sizeof(unsigned int) + sizeof(unsigned int) + i*tdt->alkioKoko, SEEK_CUR);
    if(status != 0){
        return 1;}

    status = fread(arvo, sizeof(int), lkm*tdt->alkioKoko, tdt->td); /*ylivuoto korruptoi koko tdt?*/
    if(status != lkm*tdt->alkioKoko){
        return 1;}

    return 0;
}

int tdtKirj(TdTaulu *tdt, unsigned int i, unsigned int lkm, const void *arvo)
{
    int status;

    status = fseek(tdt->td, sizeof(unsigned int) + sizeof(unsigned int) + i*tdt->alkioKoko, SEEK_CUR);
    if(status != 0){return 1;}

    status = fwrite(arvo, sizeof(int), lkm*tdt->alkioKoko, tdt->td);
    if(status != lkm*tdt->alkioKoko){return 1;}

    return 0;
}