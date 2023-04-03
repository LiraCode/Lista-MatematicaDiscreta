#include <stdio.h>
#include "libs/reverse.c"

int main(void)
{
    int a = 42;
    int m = 127;

    printf("Inverse of %d mod %d = %d\n", a, m, getInverse(a, m));
    return 0;
}