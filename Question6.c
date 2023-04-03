#include <stdio.h>
#include "libs/reverse.c"

void printCombination(LinearCombination c)
{
    printf("%d = (%d) * %d + (%d) * %d\n", c.mdc, c.s, c.a, c.t, c.b);
}

int main(void)
{
    int a = 1;
    int b = 5;
    LinearCombination result = reverseEuclides(a, b);
    printCombination(result);
    return 0;
}