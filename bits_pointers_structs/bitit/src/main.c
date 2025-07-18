#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "bitit.h"

int main(int argc, char **argv)
{
    long i = 0;
    long num = 0;
    char bitit[64] = {0};
    unsigned long mask = 1UL << 63;
    signed char eka = 0;
    short int toka = 0;
    int kolmas = 0;

    for(i = (argv[1][0] == '-') ? 1:0; i < strlen(argv[1]); i++)
    {
        num = num + (argv[1][i] - '0')*pow(10,strlen(argv[1])-i-1);
    }
    if(argv[1][0] == '-'){num = -1*num;}

    for(i = 0; i < 64; i++)
    {
        bitit[i] = (num & mask) ? 1 : 0;
        mask >>= 1;
    }
    
    for(i = 0; i < 8; i++){eka |= (bitit[56+i] & 1) << (7-i);}
    scharBitit(eka);
    kaannaScharBitit(&eka);

    for(i = 0; i < 16; i++){toka |= (bitit[48+i] & 1) << (15-i);}
    shortBitit(toka);
    kaannaShortBitit(&toka);

    for(i = 0; i < 32; i++){kolmas |= (bitit[32+i] & 1) << (31-i);}
    intBitit(kolmas);
    kaannaIntBitit(&kolmas);

    longBitit(num);
    kaannaLongBitit(&num);

    return 0;
}