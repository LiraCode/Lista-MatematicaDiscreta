#include <stdio.h>

int mdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    mdc(b, a % b);
}

int main(void)
{
    int a = 124;
    int b = 12;
    printf("MDC(%d, %d) = %d\n", a, b, mdc(a, b));
    return 0;
}