#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int start = atoi(argv[1]);
    int stop = atoi(argv[2]);

    while(start <= stop)
    {
        printf("%d: %c\n", start, start);
        start++;
    }

    return 0;
}