#include "signaalit.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string.h>

jmp_buf paluuTila;

int main(int argc, char **argv)
{
    int matched;
    int i;
    int t_i;
    int tmp;
    char input[100];

    int *taulu;
    char komento[20];
    int a;
    int b;
    int used;
    int cap;

    matched = 1;
    i = 0;
    t_i = 0;
    cap = 1;
    used = 0;

    taulu = malloc(sizeof(int));

    signal(SIGFPE, hoidaSIGFPE);
    signal(SIGSEGV, hoidaSIGSEGV);

    while(matched != 0)
    {
        fgets(input, 20, stdin);

        matched = sscanf(input, "%s %d %d", komento, &a, &b);   /*how many matched from full command*/

        if(!strcmp(komento, "lisää") || !strcmp(komento, "tulosta")){}  /*check if correct input*/
        else{matched = 0;}

        if(matched == -1){matched = 0;}

        switch(setjmp(paluuTila))
        {
            
            case 0: /*syöterivin käsittely*/

                switch(matched)
                {
                    case 0: /*empty or faulty input*/

                        return 0;

                    case 1: /*print all*/
                        
                        printf("%d", taulu[0]);
                        for(tmp=1; tmp<used; tmp++)
                        {
                            printf(" %d", taulu[tmp]);
                        }
                        printf("\n");

                        longjmp(paluuTila, 3);

                    case 2: /*print specific result*/
                        
                        printf("%d\n", taulu[a]);
                        
                        longjmp(paluuTila, 3);

                    case 3: /*add division*/
                        
                        tmp = a/b;

                        if(used + 1 > cap)
                        {
                            cap = 2*cap;
                            taulu = realloc(taulu, cap*sizeof(int));
                        }

                        taulu[t_i] = tmp;

                        t_i++;
                        used++;

                        longjmp(paluuTila, 3);
                }

            case SIGFPE: /*SIGFPE*/

                printf("Aiheutui signaali SIGFPE\n");
                break;

            case SIGSEGV: /*SIGSEGV*/

                printf("Aiheutui signaali SIGSEGV\n");
                break;

            case 3: /*just escape nested switch*/
                
                break;

            default:   /*UNKNOWN signaali*/

                break;

        }
        i++;
    }
    free(taulu);

    return 0;
}