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

    for(i = 0; i < 16; i++){toka |= (bitit[48+i] & 1) << (15-i);}

    for(i = 0; i < 32; i++){kolmas |= (bitit[32+i] & 1) << (31-i);}

    long int lx = num;  // Each test uses a different value for NUMBER.
    signed char cx = lx;
    short sx = lx;
    int ix = lx;
    printScharBits(cx);
    kaannaScharBitit(&cx); // Give the address of cx as the pointer parameter value.
    printScharBits(cx);
    printf("\n");
    printShortBits(sx);
    kaannaShortBitit(&sx); // Address of sx --> pointer to sx.
    printShortBits(sx);
    printf("\n");
    printIntBits(ix);
    kaannaIntBitit(&ix);   // Address of ix --> pointer to sx.
    printIntBits(ix);
    printf("\n");
    printLongBits(lx);
    kaannaLongBitit(&lx);  // Address of lx --> pointer to lx.
    printLongBits(lx);

    return 0;
}