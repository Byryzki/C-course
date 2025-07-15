#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int negative = argv[1][0] - '0';
    int sum = 0;

    int i;

    if(negative)
    {
        for(i=0; i<strlen(argv[1]); i++)
        {

            int one = (argv[1][strlen(argv[1])-i-1] - '0' == 1) ? 0:1; /*reverse*/
            if(one)
            {
                sum = sum + pow(2, i);
            }
        }
        sum++;
        printf("-");
    }
    else
    {
        for(i=0; i<strlen(argv[1]); i++)
        {

            int one = argv[1][strlen(argv[1])-i-1] - '0';
            if(one)
            {
                sum = sum + pow(2, i);
            }
        }
    }

    printf("%d\n", sum);

    return 0;
}