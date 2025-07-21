#ifndef KOLMIJAKO
#define KOLMIJAKO


typedef struct IntPari
{
    int x;
    int y;
} IntPari;

IntPari kolmijako(unsigned int n, int t[], int pivot1, int pivot2, int *p1, int *p2);

#endif