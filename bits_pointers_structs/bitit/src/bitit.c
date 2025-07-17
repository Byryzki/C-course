#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "bitit.h"

void scharBitit(signed char x)
{
    int i;
    char bitit[8] = {0};
    int zeros = 0;
    int ones = 0;

    unsigned char mask = 1 << 7;

    printf("%d\n", x);

    for(i = 0; i < 8; i++)
    {
        bitit[i] = (x & mask) ? 1 : 0;
        printf("%d", bitit[i]);
        mask >>= 1;
    }
    printf("\n");
    
    for(i=0; i < 8; i++){if(bitit[i] == 0){zeros++;}}
    printf("%d\n", zeros);

    for(i=0; i < 8; i++){if(bitit[i] == 1){ones++;}}
    printf("%d\n", ones);
    printf("\n");
}

void shortBitit(short int x)
{
    int i;
    char bitit[16] = {0};
    int zeros = 0;
    int ones = 0;

    unsigned short mask = 1 << 15;

    printf("%d\n", x);

    for(i = 0; i < 16; i++)
    {
        bitit[i] = (x & mask) ? 1 : 0;
        printf("%d", bitit[i]);
        mask >>= 1;
    }
    printf("\n");

    for(i=0; i < 16; i++){if(bitit[i] == 0){zeros++;}}
    printf("%d\n", zeros);

    for(i=0; i < 16; i++){if(bitit[i] == 1){ones++;}}
    printf("%d\n", ones);
    printf("\n");
}

void intBitit(int x)
{
    int i;
    char bitit[32] = {0};
    int zeros = 0;
    int ones = 0;

    unsigned int mask = 1U << 31;

    printf("%d\n", x);

    for(i = 0; i < 32; i++)
    {
        bitit[i] = (x & mask) ? 1 : 0;
        printf("%d", bitit[i]);
        mask >>= 1;
    }
    printf("\n");

    for(i=0; i < 32; i++){if(bitit[i] == 0){zeros++;}}
    printf("%d\n", zeros);

    for(i=0; i < 32; i++){if(bitit[i] == 1){ones++;}}
    printf("%d\n", ones);
    printf("\n");
}

void longBitit(long int x)
{
    int i;
    char bitit[64] = {0};
    int zeros = 0;
    int ones = 0;

    unsigned int mask = 1U << 31;

    printf("%ld\n", x);

    for(i = 0; i < 32; i++)
    {
        if(x<0){printf("1"); bitit[i] = 1;}
        else{printf("0");}
    }
    for(; i < 64; i++)
    {
        bitit[i] = (x & mask) ? 1 : 0;
        printf("%d", bitit[i]);
        mask >>= 1;
    }
    printf("\n");

    for(i=0; i < 64; i++){if(bitit[i] == 0){zeros++;}}
    printf("%d\n", zeros);

    for(i=0; i < 64; i++){if(bitit[i] == 1){ones++;}}
    printf("%d\n", ones);
}

void kaannaScharBitit(signed char *x)
{
    char originals[8] = {0};
    char result[8] = {0};
    signed char revval = 0;
    unsigned int mask = 0;
    int right = 0;
    int left = 7;

    printf("%d\n", *x);

    while(right < 8) /*construct bit array from char*/
    {
        mask = 1 << right;
        originals[left] = (*x & mask) >> right;
        result[right] = (*x & mask) >> right;

        mask = 0;
        right++;
        left--;
    }

    for(right=0; right<8; right++){revval |= (result[right] & 1) << (7-right);} /*construct char from bit array*/

    for(right=0; right<8; right++){printf("%d", originals[right]);} printf("\n");
    printf("%d\n", revval);
    for(right=0; right<8; right++){printf("%d", result[right]);} printf("\n");
    printf("\n");
}

void kaannaShortBitit(short *x)
{
    char originals[16] = {0};
    char result[16] = {0};
    short revval = 0;
    unsigned int mask = 0;
    int right = 0;
    int left = 15;

    printf("%d\n", *x);

    while(right < 16) /*construct bit array from char*/
    {
        mask = 1 << right;
        originals[left] = (*x & mask) >> right;
        result[right] = (*x & mask) >> right;

        mask = 0;
        right++;
        left--;
    }

    for(right=0; right<16; right++){revval |= (result[right] & 1) << (15-right);} /*construct char from bit array*/

    for(right=0; right<16; right++){printf("%d", originals[right]);} printf("\n");
    printf("%d\n", revval);
    for(right=0; right<16; right++){printf("%d", result[right]);} printf("\n");
    printf("\n");
}

void kaannaIntBitit(int *x)
{
    char originals[32] = {0};
    char result[32] = {0};
    int revval = 0;
    unsigned int mask = 0;
    int right = 0;
    int left = 31;

    printf("%d\n", *x);

    while(right < 32) /*construct bit array from char*/
    {
        mask = 1 << right;
        originals[left] = (*x & mask) >> right;
        result[right] = (*x & mask) >> right;

        mask = 0;
        right++;
        left--;
    }

    for(right=0; right<32; right++){revval |= (result[right] & 1) << (31-right);} /*construct char from bit array*/

    for(right=0; right<32; right++){printf("%d", originals[right]);} printf("\n");
    printf("%d\n", revval);
    for(right=0; right<32; right++){printf("%d", result[right]);} printf("\n");
    printf("\n");
}

void kaannaLongBitit(long *x)
{
    char originals[64] = {0};
    char result[64] = {0};
    long revval = 0;
    unsigned long mask = 0;
    long right = 0;
    long left = 63;

    printf("%ld\n", *x);

    while(right < 64) /*construct bit array from char*/
    {
        mask = 1UL << right;
        originals[left] = (*x & mask) >> right;
        result[right] = (*x & mask) >> right;

        mask = 0;
        right++;
        left--;
    }

    if(result[0]==1)
    {
        for(right=1; right<64; right++)
        {
            if(result[right] == 0){revval = revval + pow(2,63-right);}
        } /*construct char from bit array*/ 
        revval = -1*revval;
    }
    else
    {
        for(right=1; right<64; right++)
        {
            if(result[right] == 1){revval = revval + pow(2,63-right);}
        } /*construct char from bit array*/ 
        revval--;
    }

    for(right=0; right<64; right++){printf("%d", originals[right]);} printf("\n");
    printf("%ld\n", revval);
    for(right=0; right<64; right++){printf("%d", result[right]);} printf("\n");
}


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
    ScharBitit(eka);
    kaannaScharBitit(&eka);

    for(i = 0; i < 16; i++){toka |= (bitit[48+i] & 1) << (15-i);}
    ShortBitit(toka);
    kaannaShortBitit(&toka);

    for(i = 0; i < 32; i++){kolmas |= (bitit[32+i] & 1) << (31-i);}
    IntBitit(kolmas);
    kaannaIntBitit(&kolmas);

    kaannaLongBitit(num);
    kaannaLongBitit(&num);

    return 0;
}