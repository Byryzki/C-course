#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

#include "tulosta.h"

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
        strcpy(taulu[i], arg);

        i++;
    }

    td = freopen("filu.txt", "w", td);

    i=0;
    while(taulu[0][i] != '\0')   /*print chars to stdout*/
        {
            c = taulu[0][i];
            c2 = taulu[0][i+1];

            switch(c)
            {
                case '%':
                    fputc(arg[i], td);
                    j = j + sizeof(char);
                    break;

                default:
                    switch(c2)
                    {
                        case '%':
                            fputc('%', td);
                            i++;

                            break;

                        case 'd':
                            mag = 10000;
                            for(k = 5; k < 0; k--)
                            {
                                if((c2/mag) % mag != 0)
                                {
                                    fputc((c2/mag) % mag, td);
                                    j = j + sizeof(char);
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
                                j = j + sizeof(char);
                            }

                            param++;

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

    fclose(td);

    return j;
}