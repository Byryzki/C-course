#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int start = atoi(argv[1]);
    int stop = atoi(argv[2]);

    while(start < stop)
    {  
        int worthy = 1;
        for(int i = 1; i <= argc; i++)
        {
            if(start % atoi(argv[i]) == 0)
            {
                worthy = 0;
                break;
            }
            
        }
        
        if(worthy){printf("%d \n", start);}
        
        start++;
    }

    return 0;
}