#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i;
    int j;
    int k;
    size_t koko;
    double *lista;
    int used;
    double sum;
    int order[100] ={0};
    double tmp_lista[100] = {0};

    i = 0;
    koko = 2;
    used = 2;
    lista = malloc(koko*sizeof(double));
    sum = 0;

    while(scanf("%lf", &lista[i]) == 1) /*collect user input*/
    {
        if(koko <= used)    /*resize*/
        {
            koko = 2*koko;
            lista = realloc(lista, koko*sizeof(double));
        }

        used++;
        i++;
    }

    lista = realloc(lista, i*sizeof(double));
    lista[i+1] = '\0';

    for(k=0; k<i; k++)
    {
        for(j=0; j<i; j++)
        {
            if(j==i){}
            else
            {
                if(lista[j]>lista[k]){order[j]++;}
            }
        }
    }

    for(k=0; k<i; k++){tmp_lista[order[k]] = lista[k];}
    for(k=0; k<i; k++){lista[k] = tmp_lista[k];}

    printf("Luettiin %d lukua:", i);
    for(j=0; j<i; j++)
    {
        printf(" %.3f", lista[j]);

        sum = sum + lista[j];
    }
    printf("\n");

    printf("Summa: %.3f\n", sum);
    printf("Keskiarvo: %.3f\n", sum/i);

    free(lista);

    return 0;
}