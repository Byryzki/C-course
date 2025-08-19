#include <stdio.h>
#include <stdlib.h>
#include "numeroita.h"
#include "komplementti.h"
#include "murtofilu.h"
#include <linkki.h>

int main(int argc, char **argv)
{
    int lukum;
    char **nums;
    char **komps;
    unsigned int num;
    FILE *on;
    double a;

    lukum = argc - 1;

    /*
    nums = numeroita(argv[1], argv[2], argv[3]);
    printf("pienin: %s\n", nums[0]);
    printf("suurin: %s\n", nums[1]);

    free(nums[0]);
    free(nums[1]);
    free(nums);
    
    murtofilu(on, argv[1], argv[2]);
    

    komplementti("1100");
    
    */

    a = 0.2;
    linkki(0.2);
    

    return 0;
}