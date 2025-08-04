#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i;
    int j;
    size_t koko;
    double *lista;
    int cap;
    int used;
    double sum;
    double avg;

    i = 0;
    koko = 2;
    used = 2;
    cap = 0;
    lista = malloc(koko*sizeof(double));
    sum = 0;
    avg = 0;

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

    lista = realloc(lista, (i+1)*sizeof(double));

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
}