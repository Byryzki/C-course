#include "piste3d.h"
#include <stdio.h>
#include <math.h>

double etaisyys(Piste3D a, Piste3D b)
{
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
}

void tulosta(Piste3D p, int prec)
{
    printf("(%.*f, %.*f, %.*f)", prec, p.x, prec, p.y, prec, p.z);
}