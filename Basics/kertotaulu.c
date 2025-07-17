#include <stdio.h>

int main()
{
    int i = 0;
    for(i=0; i<=15; i++)
    {
        int j = 0;
        for(j=0; j<=15; j++)
        {   
            if(i == 0)  /*headers*/
            {
                if(j == 0) 
                {
                    printf("   ");
                    printf("x");
                }
                else
                {
                    printf("%4d", j);
                }
            }
            else
            {
                if(j == 0) 
                {
                    printf("%4d", i);
                }
                else
                {
                    printf("%4d", i*j);
                }
            }
        }   
        printf("\n");
    }   
    return 0;
}