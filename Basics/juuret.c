#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    int precision = atoi(argv[1]);
    
    int i = 2;
    for(;i < argc; i++)
    {
        double val = atof(argv[i]);
        double juuri = sqrt(val);
        printf("sqrt(%.*f) = %.*f\n", precision, val, precision, juuri);
    }

    return 0;
}