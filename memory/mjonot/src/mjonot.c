#include "mjonot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** kopioi_mjt(char **strs, size_t n)
{
    int i;
    int j;
    int len;

    char **result = malloc(n*sizeof(char*));

    for(i=0; i<n; i++)
    {
        len = strlen(strs[i]);
        result[i] = malloc(len*sizeof(char)+sizeof(char));  /*leave room for /0*/

        for(j=0; j<=len+1; j++)
        {
            result[i][j] = strs[i][j];
        }
    }
    return result;
}

char ** jarjesta_mjt(char **strs, size_t n, int (*cmp)(const char*, const char *))
{
    int i;
    int j;
    int len;

    int pos[100];
    char **jono;
    jono = malloc(n*sizeof(char *));


    for(i=0; i<n; i++)  /*how many of the other elements are bigger than*/
    {
        pos[i] = 0;
        for(j=0; j<n; j++)
        {
            if(i==j){}
            else if(!cmp(strs[i], strs[j])){pos[i]++;}
        }
    }    
       
    for(i=0; i<n; i++)
    {   
        len = strlen(strs[i]);
        jono[pos[i]] = malloc(len*sizeof(char)+sizeof(char)); 

        for(j=0; j<len; j++)
        {
            jono[pos[i]][j] = strs[i][j];
        }
        jono[pos[i]][len] = '\0';
    }

    return jono;
}