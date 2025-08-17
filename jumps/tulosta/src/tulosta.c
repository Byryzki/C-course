#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <ctype.h>
#include <signal.h>

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
    uintptr_t addr2int;
    char addr2char[100];

    char **taulu;

    j = 0;
    param = 1;

    va_start(args, mj);

    taulu = malloc(5*sizeof(char *));
    taulu[0] = malloc(100*sizeof(char));
    strcpy(taulu[0], mj);

    i=0;
    while(taulu[0][i] != '\0')   /*print chars to stdout*/
        {
            c = taulu[0][i];
            c2 = taulu[0][i+1];

            switch(c)
            {
                default:
                    fputc(taulu[0][i], td);
                    j++;
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
                            
                            mj = va_arg(args, const char *);    /*next arg*/
                            k = 0;

                            addr2int = (int)(intptr_t)mj;
                            sprintf(addr2char, "%ld", addr2int);

                            while(addr2char[k] != '\000')
                            {
                                fputc(addr2char[k], td);
                                k++;
                                j++;
                            }

                            i++;
                            break;

                        case 's':

                            mj = va_arg(args, const char *);    /*next arg*/

                            for(k=0; k < strlen(mj); k++)
                            {
                                fputc(mj[k], td);
                                j++;
                            }

                            i++;
                            break;

                        case 'c':

                            mj = va_arg(args, const char *);    /*next arg*/
                            addr2int = (int)(intptr_t)mj;

                            tmp = (char)addr2int;
                        
                            fputc((char)tmp, td);

                            j++;
                            i++;
                            break;
                    }
            }

            i++;
        }

    i=0;
    for(i=0; i<5; i++)
    {
        free(taulu[i]);
    }
    free(taulu);

    return j;
}