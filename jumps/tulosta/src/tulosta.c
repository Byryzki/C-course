#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <ctype.h>

#include "tulosta.h"

// helper: check if mj looks like a valid C string
static int looks_like_string(const char *mj) {
    if (mj == NULL) return 0;

    // try to check if first byte is printable (heuristic)
    unsigned char c = (unsigned char) mj[0];
    return (isprint(c) || c == '\0');
}

size_t tulosta(FILE *td, const char *mj, ...)
{
    int i;
    size_t j;
    int param;
    const char *arg;
    va_list args;
    char c, c2, tmp;
    int mag;
    int k;

    char **taulu;
    char *rivi;

    j = 0;
    param = 1;

    va_start(args, mj);

    taulu = malloc(5*sizeof(char *));
    taulu[0] = malloc(100*sizeof(char));
    strcpy(taulu[0], mj);

    i=1;
    while((arg = va_arg(args, const char*)) != NULL)  /*copy args into a structure*/
    {
        taulu[i] = malloc(100*sizeof(char));

        if(!looks_like_string(arg)) /*arg not a const char*/
        {
            arg = (int)(intptr_t) arg;

            
        }   

        strcpy(taulu[i], arg);

        i++;
    }

    i=0;
    while(taulu[0][i] != '\0')   /*print chars to stdout*/
        {
            c = taulu[0][i];
            c2 = taulu[0][i+1];

            switch(c)
            {
                default:
                    fputc(taulu[param][i], td);
                    j++;
                    i++;
                    break;

                case '\n':

                fputc('\n', td);
                j++;    
                return j;

                case '%':
                    switch(c2)
                    {
                        case '%':
                            fputc('%', td);
                            j++;
                            i++;

                            break;

                        case 'd':
                            mag = 10000;
                            for(k = 5; k < 0; k--)
                            {
                                if((c2/mag) % mag != 0)
                                {
                                    fputc((c2/mag) % mag, td);
                                    j++;
                                }
                                mag = mag / 10;
                            }
                            
                            i++;
                            param++;

                            break;

                        case 's':

                            for(k=0; k < strlen(taulu[param]); k++)
                            {
                                fputc(taulu[param][k], td);
                                j++;
                            }

                            param++;
                            i++;
                            break;

                        case 'c':
                            tmp = taulu[param];
                            fputc(tmp, td);

                            param++;

                            break;
                    }
            }

            i++;
        }

    for(i=0; i<5; i++)
    {
        free(taulu[i]);
    }
    free(taulu);

    return j;
}