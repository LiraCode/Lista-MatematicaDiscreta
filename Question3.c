#include <stdio.h>
#include <math.h>

int _isPrime(int divisor, int n)
{
    if (n <= 1)
    {
        return 0;
    }
    if (divisor > (double)sqrt((double)n))
    {
        return 1;
    }

    if (n % divisor == 0)
    {
        return 0;
    }
    _isPrime(divisor + 1, n);
}

int isPrime(int n)
{
    return _isPrime(2, n);
}

void factor(int n, int primeFactor)
{
    if (n == 1)
    {
        return;
    }
    if (isPrime(primeFactor))
    {
        while (n % primeFactor == 0)
        {
            printf("%d", primeFactor);
            if (n != primeFactor)
            {
                printf(" * ");
            }
            n = n / primeFactor;
        }
    }
    factor(n, primeFactor + 1);
}

int main(void)
{
    int n = 120;
    printf("%d = ", n);
    factor(n, 1);
    return 0;
}