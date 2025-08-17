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
    va_list args;
    char c, c2, tmp;
    int k;
    uintptr_t addr2int;
    char addr2char[100];
    char **taulu;

    j = 0;

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

                            if(((addr2int/10000) % 10) != 0)
                            {
                                addr2char[k] = '0' + ((addr2int/10000) % 10);
                                addr2char[k+1] = '0'; addr2char[k+2] = '0'; addr2char[k+3] = '0'; addr2char[k+4] = '0';
                                k++;
                                j++;
                            }

                            if(((addr2int/1000) % 10) != 0)
                            {
                                addr2char[k] = '0' + ((addr2int/1000) % 10);
                                addr2char[k+1] = '0'; addr2char[k+2] = '0'; addr2char[k+3] = '0';
                                k++;
                                j++;
                            }
                            else if(k!=0){k++;}
                            
                            if(((addr2int/100) % 10) != 0)
                            {
                                addr2char[k] = '0' + ((addr2int/100) % 10);
                                addr2char[k+1] = '0'; addr2char[k+2] = '0';
                                k++;
                                j++;
                            }
                            else if(k!=0){k++;}

                            if(((addr2int/10) % 10) != 0)
                            {
                                addr2char[k] = '0' + ((addr2int/10) % 10);
                                addr2char[k+1] = '0';
                                k++;
                                j++;
                            }
                            else if(k!=0){k++;}

                            if((addr2int % 10) != 0)
                            {
                                addr2char[k] = '0' + (addr2int % 10);
                                k++;
                                j++;
                            }

                            k=0;
                            while(addr2char[k] != '\000'){fputc(addr2char[k], td); k++;}

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