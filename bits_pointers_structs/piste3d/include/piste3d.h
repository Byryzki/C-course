#ifndef PISTE3D
#define PISTE3D

typedef struct Piste3D
{
    double x;
    double y;
    double z;
} Piste3D;

double etaisyys(Piste3D a, Piste3D b);
void tulosta(Piste3D p, int prec);

#endif