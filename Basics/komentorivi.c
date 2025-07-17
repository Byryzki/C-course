#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 1; /*skipping the program name in args*/

    while(i < argc)
    {
        printf("%d: ", i);
        printf("%s ", argv[i]);
        printf("(pituus: %d)\n", (int)strlen(argv[i]));
        i++;
    }

    return 0;
}