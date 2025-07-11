#include <stdio.h>
#include <math.h>
#include <string.h>

int solutions(double a, double b, double c)
{
    int amount = b*b-4*a*c;

    if(amount < 0){return 0;} 
    else if(amount == 0){return 1;}
    
    return 2;  
}

void onesol(double a, double b)
{
    printf("%.3f\n", -b/(2*a));
}

void twosol(double a, double b, double c)
{
    double sol1 = (-b+sqrt(b*b-4*a*c))/(2*a);
    double sol2 = (-b-sqrt(b*b-4*a*c))/(2*a);
    
    double bigger = (sol1 >= sol2) ? sol1 : sol2;
    double smaller = (sol1 <= sol2) ? sol1 : sol2;
    
    printf("%.3f ", smaller);
    printf("%.3f\n", bigger);
}


int main(int argc, char **argv)
{
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    int sol = solutions(a,b,c);
    
    if(sol == 1)
    {
        onesol(a,b);
    }
    else if(sol == 2)
    {
        twosol(a,b,c);
    }
    else
    {
        printf("Ei ratkaisua\n");
    }

    return 0;
}