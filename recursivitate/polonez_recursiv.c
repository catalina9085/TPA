#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int prefix(char *s, int *i) {
    if(*i>strlen(s))
        return 0;
    char op = s[(*i)++];

    if (isdigit(op))
        return op - '0';

    int e1 =prefix(s,i);
    int e2 =prefix(s,i);

    switch (op) {
        case '+':
            return e1 + e2;
        case '-':
            return e1 -e2;
        case '*':
            return e1 *e2;
        case '/':
            return e1 /e2;
        default:
            exit(-1);
    }
}


int main() {
    char s[] = "+*34-5+01";
    int i=0;
    printf("Rezultat: %d\n", prefix(s,&i));
    return 0;
}
