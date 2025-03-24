#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);

    int rowlen = b-a+1;
    int collen = d-c+1;

    int row[100];
    int col[100];

    int temp;
    int kymmen;

    int iter = 0;
    int iter2 = 0;


    while(iter <= rowlen)
    {
        row[iter] = a+iter;
        iter++;
    }

    iter = 0;
    while(iter <= collen)
    {
        col[iter] = c+iter;
        iter++;
    }

    kymmen = 0;
    if(row[rowlen-1] > col[collen-1])
    {
        int temp = row[rowlen-1]*col[collen-1];
        while(temp != 0)
        {
            temp = temp/10;
            kymmen++;
        }
    }
    else
    {
        temp = col[collen-1]*row[rowlen-1];
        while(temp != 0)
        {
            temp = temp/10;
            kymmen++;
        }
    }

    iter = 0;
    for(; iter < kymmen+1; iter++){printf(" ");}  /*matrix index 1,1*/
    iter = 0;
    for(; iter < rowlen; iter++){printf("%*.d", kymmen+1, row[iter]);}
    printf("\n");

    iter = 0;   /*actual table*/
    for(; iter < collen; iter++)
    {
        printf("%*.d", kymmen+1, col[iter]);

        iter2 = 0;
        for(; iter2 < rowlen; iter2++)
        {
            printf("%*.d", kymmen+1, col[iter]*row[iter2]);
        }
        printf("\n");
    }

    return 0;
}