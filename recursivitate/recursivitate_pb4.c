#include <stdio.h>
#include <stdlib.h>

/*4.  Scrieţi o funcţie care calculează cu o precizie dată (de exemplu 1e-6) limita şirului xn+1=f(xn)
, presupunând că există, cu x0 şi f date (f ca si pointer la functie). Calculaţi astfel valorile
 unor termeni infiniţi, cum ar fi sau √x+√x+ ...√x*/

typedef double(*func)(double);

double calcul(double x)
{
    return sqrt(x+sqrt(x));
}

double limita(double x0,func f,double precizie)
{
    double x1=f(x0);
    while(x1-x0>precizie)
    {
        x0=x1;
        x1=limita(x1,f,precizie);
    }
    return x1;
}

int main()
{
    double x0=1.0;
    printf("%lf",limita(x0,calcul,1e-6));

    return 0;
}
