
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int g;
    int p;
    double r; // raportul pret/greutate
} obiect;
double fmax(double x,double y)
{
    if(x<=y)
        return y;
    return x;
}
double back(obiect *v, int n, int gmax, int i, int currentg, double currentp) {
    // Verificăm condiția de oprire
    if (i == n || currentg == gmax)
        return currentp;

    // Dacă obiectul curent încă mai poate fi adăugat în rucsac
    if (currentg + v[i].g <= gmax) {
        return back(v,n,gmax,i+1,currentg+v[i].g,currentp+v[i].p);
    } else { // Dacă obiectul curent nu mai poate fi adăugat integral în rucsac
        // Calculăm profitul adăugând o fracțiune din obiectul curent
        int rest = gmax - currentg;
        double fraction = (double) rest / v[i].g;
        return currentp + (fraction * v[i].p);
    }
}

int compare(const void *a, const void *b) {
    obiect *obj1 = (obiect *)a;
    obiect *obj2 = (obiect *)b;
    if (obj1->r < obj2->r)
        return 1;
    else if (obj1->r > obj2->r)
        return -1;
    else
        return 0;
}

double maxProfit(obiect *v, int n, int gmax) {
    // Sortăm obiectele în funcție de raportul pret/greutate
    qsort(v, n, sizeof(obiect), compare);

    double total = 0.0;
    int currentg = 0;

    for (int i = 0; i < n; i++) {
        if (currentg + v[i].g <= gmax) {
            total += v[i].p;
            currentg += v[i].g;
        } else {
            int rest = gmax - currentg;
            total += (double)rest * v[i].r;
            break;
        }
    }

    return total;
}
void generator_obiecte(obiect *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i].g = rand() % 1000 + 1; // greutate între 1 și 100
        v[i].p = rand() % 1000 + 1; // profit între 1 și 100
        v[i].r=(double)v[i].p/v[i].g;
    }
}

void afisare(obiect *v,int n)
{
    for(int i=0;i<n;i++)
        printf("%d %d %lf\n",v[i].g,v[i].p,v[i].r);
}



int main() {

    srand(time(NULL));
    int n=100;
    obiect v[n];
    generator_obiecte(v,n);
    int gmax = rand() % 10000 + 1;
    printf("gmax:%d\n",gmax);
    afisare(v,n);


    clock_t start = clock();
    double profit_greedy=maxProfit(v,n,gmax);
    clock_t end=clock();
    double greedy_time = ((double) (end - start)*1000.0) / CLOCKS_PER_SEC;

    start = clock();
    double profit_back=back(v,n,gmax,0,0,0.0);
    end=clock();
    double back_time = ((double) (end - start)*1000.0) / CLOCKS_PER_SEC;

    printf("profit greedy:%.2lf\nprofit backtracking:%.2lf\n",profit_greedy,profit_back);
    printf("timp greedy:%.2lf\ntimp backtracking :%.2lf\n",greedy_time,back_time);

    return 0;
}

