#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "luku.h"

char * lueKunnes(FILE *virta, char erotin, size_t *pituus)
{
    char *jono;
    int tmp;
    int mark = 0;
    size_t koko = 1;
    size_t used = 0;

   jono = malloc(sizeof(char));

    while(1)
    {
        tmp = fgetc(virta);

        if(tmp == EOF)
        {
            used = 0;
            break;
        }
        if((char)tmp == erotin)
        {
            mark = 1;
            break;
        }

        if(used >= koko)
        {
            koko = 2*koko;
            jono = realloc(jono, koko);
        }

        jono[used] = (char)tmp;
        used++;
    }

    if(!used && !mark)
    {
        jono = realloc(jono, used*sizeof(char)); /*effective freeing of this memory*/
    }
    else if(!used && mark)
    {
        jono = realloc(jono, sizeof(char));
        jono[0] = '\0';
    }
    else
    {
        jono = realloc(jono, (used+1)*sizeof(char));
        jono[used+1] = '\0';
    }

    *pituus = used;

    return jono;
}