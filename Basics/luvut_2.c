#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int start = atoi(argv[1]);
    int stop = atoi(argv[2]);
    int first = 1;

    while(start < stop)
    {  
        int worthy = 1;
        int i = 1;
        for(; i < argc; i++)
        {
            if(start == atoi(argv[i])){break;}
            if(start % atoi(argv[i]) == 0)
            {
                worthy = 0;
                break;
            } 
        }
        
        if(worthy)
        {
            if(first){
                printf("%d", start);
                first = 0;
            }
            else{
                printf(" %d", start);
            }
        }
        
        start++;
    }
    if(!first){printf("\n");}
    return 0;
}