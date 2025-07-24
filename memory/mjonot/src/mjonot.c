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