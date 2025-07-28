#ifndef KERTOTAULU
#define KERTOTAULU

#include <stdio.h>

typedef unsigned int uint;

typedef struct Kertotaulu
{
    uint a;
    uint b;
    uint c;
    uint d;
    uint **kertotaulu;
} Kertotaulu;
 
Kertotaulu * luoKertotaulu(uint a, uint b, uint c, uint d);

void tuhoaKertotaulu(Kertotaulu *kt);

#endif