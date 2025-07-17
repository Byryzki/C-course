#include <stdio.h>
#include <stdlib.h>
#include "geometria.h"

int main(int argc, char **argv)
{
    int i;
    
    printf("Piin arvo: %.19Lf\n", PII);

    for(i=1; i < argc; i++)
    {
        long double circumference = 2*PII*atof(argv[i]);
        
        printf("Säteen %.6f omaavan ympyrän ala ja pallon tilavuus: %.10Lf ja %.10Lf\n", atof(argv[i]), ympyranAla(atof(argv[i])), pallonTilavuus(atof(argv[i])));
        printf("Säteen %.6f omaavan ympyrän piiri on %.10Lf\n", atof(argv[i]), circumference);
    }

    return 0;
}