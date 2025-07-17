#include <stdio.h>
#include <math.h>

#include "geometria.h"

long double ympyranAla(double r)
{
    return PII*pow(r,2);
}

long double pallonTilavuus(double r)
{
  return 4*PII*pow(r, 3)/3;
}