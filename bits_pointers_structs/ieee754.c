#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double fraction(char sample[])
{
    int i;
    double frac = 0;

    for(i=0; i < 23; i++)
    {
        if(sample[i] - '0')
        {
            frac = frac + pow(2,-i-1);
        }
    }
    frac++;

    return frac;
}

int exponent(char sample[])
{
    int i;
    int ii = 0;
    int exp = 0;

    for(i=7; i>=0; i--)
    {
        int back = sample[i] - '0';
        int power = pow(2, ii);

        exp = exp + back * power;

        ii++;
    }
    exp = exp - 127;

    return exp;
}

char sign(char sample)
{
    char merkki = (sample-'0' == 0) ? '+' : '-';
    return merkki;
}

double overall(double jako, int e, signed int merkki)
{
    double tulos = pow(2, e) * jako;

    if(merkki == '-'){tulos = -1*tulos;};
    
    return tulos;
}

int main(int argc, char **argv)
{
    int i;
    
    char frac[23];
    char exp[8];
    double jako;
    int e;
    char merkki;

    for(i=0; i<24; i++){frac[i] = argv[1][strlen(argv[1])-23+i];}
    jako = fraction(frac);
    printf("%.15f\n", jako);

    for(i=1; i<=8; i++){exp[i-1] = argv[1][i];}
    e = exponent(exp);
    printf("%.d\n", e);

    merkki = sign(argv[1][0]);
    printf("%c\n", merkki);

    printf("%.15f\n", overall(jako, e, merkki));

    return 0;
}