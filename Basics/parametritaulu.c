#include <stdio.h>
#include <string.h>

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
    int width = 9 + longst;

    int i = 0;
    for(; i<width+1; i++){printf("#");} printf("\n");

    for(i=1; i<argc; i++)
    {
        int ii;
        
        printf("#%4d", i); printf(" | ");
        printf("%s", argv[i]);
        for(ii=7+strlen(argv[i]); ii<width-1; ii++){printf(" ");} printf("#\n");

        if(i != argc-1)
        {
            printf("#----+-"); for(ii=0; ii<=longst+1;ii++){printf("-");} printf("#\n");
        }
    }

    for(i=0; i<width+1; i++){printf("#");} printf("\n");

    return 0;   //argc:llä pakko kikkailla leveys :/
}