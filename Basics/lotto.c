#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int Wnumbers[7] = {0};
    int LotteryTicket[7] = {0};
    int common[7] = {0};
    int hits = 0;

    int i = 1;
    int j = 0;
    
    while(i <= argc/2)
    {
        Wnumbers[i-1] = atoi(argv[i]);
        LotteryTicket[i-1] = atoi(argv[i+7]);

        i++;
    }

    i = 0; 
    printf("Voittorivi:");   
    while(i < argc/2)
    {
        printf(" %d", Wnumbers[i]);

        i++;
    }
    printf("\n");

    i = 0;   
    printf("Lottorivi:"); 
    while(i < argc/2)
    {
        printf(" %d", LotteryTicket[i]);

        i++;
    }
    printf("\n");

    i = 0;    
    while(i < argc/2)  /*lottorivi*/
    {
        while(j < argc/2)  /*voittorivi*/
        {
            if(LotteryTicket[i] == Wnumbers[j])
            {
                common[i] = LotteryTicket[i];
                hits++;
            }
            j++;
        }
        j = 0;
        i++;
    }

    i = 0;
    if(hits > 0)
    {
        printf("%d oikein:", hits);

        while(i < argc/2)
        {
            if(common[i] != 0){printf(" %d", common[i]);}
            i++;
        }
    }

    else
    {
        printf("Ei yhtään oikein!");
    }

    printf("\n");
    return 0;
}