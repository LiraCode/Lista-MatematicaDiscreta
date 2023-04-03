#include <stdio.h>
#include "libs/reverse.c"

void printCombination(LinearCombination c)
{
    printf("%d = (%d) * %d + (%d) * %d\n", c.mdc, c.s, c.a, c.t, c.b);
}

int main(void)
{
    int a;
    int b;
    printf("Entre dois números inteiros: ");
    scanf("%d %d", &a, &b);
    LinearCombination result = reverseEuclides(a, b);
    printCombination(result);
    return 0;
}