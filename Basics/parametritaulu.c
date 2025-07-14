#include <stdio.h>
#include <string.h>
#include <math.h>

int longest(int amount, char **params)
{
    int longst = 0;
    int iter = 1;
    for(iter = 1; iter < amount; iter++)
    {
        longst = (strlen(params[iter]) > longst) ? strlen(params[iter]) : longst;   /* Comparison to find the longest */
    }
    return longst;
}


int main(int argc, char **argv)
{
    int longst = longest(argc, argv);
    int kerrannaisyksikko = floor(log10(argc-1));
    int width = 7 + kerrannaisyksikko + longst;

    int i = 0;

    for(; i<2+kerrannaisyksikko+1+3+longst+2; i++){printf("#");} printf("\n");

    for(i=1; i<argc; i++)
    {
        int ii;
        int numlen = floor(log10(i));
        
        printf("#%*s%d", kerrannaisyksikko+1 - numlen, " ", i);
        printf(" | %s", argv[i]);
        printf("%*.s", longst-strlen(argv[i]), " "); printf(" #\n");

        if(i != argc-1)
        {
            printf("#"); for(ii=0; ii<=kerrannaisyksikko+1; ii++){printf("-");} printf("-+-"); for(ii=0; ii<=longst; ii++){printf("-");} printf("#\n");
        }
    }

    for(i=0; i<=width; i++){printf("#");} printf("\n");

    return 0;   
}