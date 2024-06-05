#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int g;
    int p;
    double r; // raportul pret/greutate
} obiect;


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

int main() {
    FILE *f1 = fopen("rucsacfr.in", "r");
    FILE *f2 = fopen("rucsacfr.out", "w");
    if(!f1 ||!f2)
    {
        perror(NULL);
        return 1;
    }
    int n, k;
    fscanf(f1, "%d %d", &n, &k);

    obiect v[n];
    for (int i = 0; i < n; i++) {
        fscanf(f1, "%d %d", &v[i].g, &v[i].p);
        v[i].r= (double)v[i].p / v[i].g;
    }

    fprintf(f2, "%.2lf\n", maxProfit(v, n, k));

    fclose(f1);
    fclose(f2);
    return 0;
}

