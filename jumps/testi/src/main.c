#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    double tmp;
    int lukum;

    lukum = argc - 1;

    tmp = atof(argv[1]);
    printf("%.3f", tmp);

    return 0;

}