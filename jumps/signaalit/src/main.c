#include "signaalit.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <setjmp.h>

int main(int argc, char *argv)
{
    int done;
    int i;
    int t_i;
    int tmp;
    char input[20];
    int a;
    int b;
    int taulukko[10];

    done = 0;
    t_i = 0;

    signal(SIGFPE, hoidaSIGFPE);
    signal(SIGSEGV, hoidaSIGSEGV);

    while(!done)
    {
        scanf("%s", input);
        if(input[0] == 'l' && input[5] == ' ')  /*loose test for lisää*/
        {
            a = input[6];
            b = input[8];

            taulukko[t_i] = a/b;
            t_i++;
        }
        else if(input[0] == 't' && input[7] == ' ')  /*loose test for tulosta*/
        {
            i = input[8];

            prinf("%d", taulukko[i]);
        }
        else if(input[0] == 't' && input[7] == 0)  /*loose test for tulosta kaikki*/
        {
            tmp = t_i;
            prinf("%d", taulukko[0]);
            while(tmp != 0)
            {
                prinf(" %d", taulukko[i]);
                tmp--;
            }

        }

        if(input[0] == 0){done = 1;}

    }

    return 0;
}