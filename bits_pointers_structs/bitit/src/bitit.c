#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "bitit.h"

void scharBitit(signed char x)
{
    printf("%s", x);

    int num = x - '0';

    char bitit[8] = {0};
    int sum = 0;
    int i = 7;
    while(sum != num)
    {
        if(pow(2,i) <= num)
        {
            sum = sum + pow(2,i);
            bitit[i] = 1;
        }
        else if(pow(2,i) == num){break;}

        i--;
    }
    printf("%s", bitit);

    int zeros = 0;
    for(i=0; i < 7; i++){if(bitit[i] = 0){zeros++;}}

    int ones = 0;
    for(i=0; i < 7; i++){if(bitit[i] = 1){ones++;}}
}

void shortBitit(short int x)
{

}

void intBitit(int x)
{

}

void longBitit(long int x)
{
    
}

int main(int argc, char **argv)
{
    scharBitit(*argv[1]);

    return 0;
}