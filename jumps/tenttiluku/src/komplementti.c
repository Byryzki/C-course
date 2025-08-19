#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "komplementti.h"

void komplementti(char *bitit)
{
    int i;
    int len;
    char buf[100];

    len = 0;
    while(bitit[len] != '\0'){len++;}
    
    for(i=0; i<len; i++)
    {
        buf[i] = (bitit[i] == '0') ? '1': '0';
    }

    i--;
    while(1)
    {
        if(buf[i] == '0')
        {
            buf[i] = '1';
            break;
        }
        else
        {
            buf[i] = '0';
            
            if(buf[i-1] == '0')
            {
                buf[i-1] = '1';
                break;
            }
        }
        i--;
    }

    printf("Komplementti: %s\n", buf);
}   