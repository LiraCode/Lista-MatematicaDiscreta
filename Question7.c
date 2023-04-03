#include <stdio.h>
#include "libs/reverse.c"

int main(void)
{
    int a;
    int m;
    printf("Entre dois números inteiros (a e m): ");
    scanf("%d %d", &a, &m);

    printf("Inversa de %d mod %d = %d\n", a, m, getInverse(a, m));
    return 0;
}