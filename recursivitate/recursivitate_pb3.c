#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
3. Rădăcina unei funcţii. Găsiţi, cu o aproximaţie dată, rădăcina unică a unei funcţii continue şi monotone f pe un interval [a, b] pe care funcţia schimbă semnul. (Rezolvaţi pentru un caz concret al valorilor a, b şi a funcţiei f-transmisa ca si pointer la functie).

Problema se rezolvă înjumătăţind la fiecare pas intervalul de căutare, până când acesta devine mai mic decât precizia cerută. Se calculează valoarea funcţiei în mijlocul intervalului. Indiferent de semnul ei, cum în funcţia are semne diferite în capetele intervalului, ea schimbă semnul pe una din cele două jumătăţi de interval. Ajungem astfel la aceeaşi problemă, dar cu intervalul redus la jumătate. Cazul de bază e când lungimea intervalului e sub precizia cerută: orice valoare din interval e o aproximaţie suficientă.

Se poate eventual testa suplimentar dacă funcţia e nulă în mijlocul intervalului, şi returna direct rădăcina în acest caz.

*/
typedef double(*func)(double);

double calcul(double x)
{
    return x*x*x+x-1;  //consideram functia x^3+x-1
}

double radacina(double a,double b,func f,double precizie)
{
    double x=(a+b)/2;

    if(f(x)==0.0 || (b-a)/2<=precizie)
        return x;

    if(f(a)*f(x)<0)
        return radacina(a,x,f,precizie);
    else
        return radacina(x,b,f,precizie);
}

int main()
{
    double a=0,b=1,precizie=0.00005;
    printf("%lf",radacina(a,b,calcul,precizie));

    return 0;
}
