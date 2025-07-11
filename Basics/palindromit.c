#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int iter = 1;
    int palindrome = 1;

    for(;iter < argc; iter++)
    {
        int iter2 = 0;
        int N = strlen(argv[iter]);

        for(;iter2 < strlen(argv[iter]); iter2++)
        {
            char a = argv[iter][iter2];
            char b = argv[iter][N-1-iter2];

            if(tolower(a) != tolower(b))
            {
                palindrome = 0;
                break;
            }
            else if(iter2 >= N-1-iter2){break;}
        }
        printf("\""); printf("%s", argv[iter]); printf("\": ");
        if(palindrome){printf("on palindromi\n");}
        else{{printf("ei ole palindromi\n");}}

        palindrome = 1;
    }
}
