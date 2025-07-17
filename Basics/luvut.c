#include <stdio.h>

int main()
{
    int i = 0;
    int first = 1;
    while(i<=100)
    {
        if(i%2!=0 && i%3!=0 && i%5!=0)
        {
            if(!first){printf(" ");}
            first = 0;
            printf("%d", i);
        }
        i++;
    }
    printf("\n");

    return 0;
}