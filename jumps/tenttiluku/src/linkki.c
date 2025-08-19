#include "linkki.h"
#include <stdio.h>
#include <stdlib.h>

void linkki(double a)
{
    int i;
    int end;
    node **taulu;
    node *paa;

    end = 4;
    taulu = malloc(end*sizeof(node*));

    for(i=0; i<end; i++)
    {
        taulu[i] = malloc(sizeof(node));
        taulu[i]->arvo = a*i;

        if(i!=0)
        {
            taulu[i]->prev = taulu[i-1];
        }
        else{paa = taulu[0];}
    }

    for(i=end-1; i>=0; i--)
    {
        if(i!=end)
        {
            taulu[i]->next = taulu[i+1];
        }
    }

    printf("Arvot listasta: ");
    while(paa != NULL)
    {
        printf("%.3f ", paa->arvo);

        paa = paa->next;
    }
    printf("\n");

    for(i=0; i<end; i++){free(taulu[i]);}
    free(taulu);
}