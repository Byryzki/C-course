#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double smallest(int argc, char **array)
{
    double smallest = 9999.0;
    
    int iter = 1;
    for(; iter < argc; iter++)
    {
        if(atof(array[iter]) < smallest){smallest = atof(array[iter]);}
    }

    return smallest;
}

double biggest(int argc, char **array)
{
    double biggest = -9999.0;
    
    int iter = 1;
    for(; iter < argc; iter++)
    {
        if(atof(array[iter]) > biggest){biggest = atof(array[iter]);}
    }

    return biggest;
}

void uniques(int argc, char **array)
{
    int iter = 0;
    int iter2 = 0;
    int freq = 0;
    int first = 1;
    char copy[100];
    int multiple = 0;

    for(int i = 1; i < argc; i++)
    {
        copy[i-1] = atoi(array[i]);
    }

    for(iter = 1; iter < argc; iter++)
    {
        for(iter2 = 1; iter2 < argc; iter2++)
        {
            if(atoi(array[iter2]) == atoi(array[iter]) && iter2 != iter)
            {
                multiple = 1;
            }
        }
        if(!multiple)
        {
            if(first){printf("Ainutlaatuiset:");}
            printf(" %.6f", atof(array[iter]));
            first = 0;  
        }

        multiple = 0;
    }

    if(!first){printf("\n");}
}

void frequent(int argc, char **array)
{
    int iter = 0;
    int iter2 = 0;
    int freq = 0;
    int big = 0;
    int first = 1;
    int freqs[100] = {0};

    for(iter = 0; iter < argc; iter++)
    {
        for(iter2 = 0; iter2 < argc; iter2++)
        {
            if(atof(array[iter2]) == atof(array[iter]))
            {
                freq++;
            }
        }
        freqs[iter] = freq;
        freq = 0;
    }

    for(iter = 0; iter < argc; iter++)
    {
        if(freqs[iter] > big){big = freqs[iter];}
    }

    if(big > 1)
    {
        for(iter = 0; iter < argc; iter++)
        {
            if(freqs[iter] == big)
            {
                freq++;
            }
        }

        printf("Useimmiten esiintyneet (%d kertaa):", big);

        for(iter = 0; iter < argc; iter++)
        {
            if(freqs[iter] == big)
            {
                for(iter2 = 0; iter2 < argc; iter2++)
                { 
                    if(atof(array[iter2]) == atof(array[iter]))
                    {
                        if(!first){freqs[iter2] = 0;}
                        else
                        {
                            printf(" %.6f", atof(array[iter]));
                            first = 0;
                        }
                    }
                }            
            }
            first = 1;
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    double smol;
    double big;
    
    smol = smallest(argc, argv);
    printf("Pienin: %.6f", smol);
    printf("\n");

    big = biggest(argc, argv);
    printf("Suurin: %.6f", big);
    printf("\n");

    uniques(argc, argv);

    frequent(argc, argv);

    return 0; /*alin testi ei mene läpi*/
}