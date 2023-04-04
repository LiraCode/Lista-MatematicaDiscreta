#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    if (n == 2)
    {
        return 1;
    }
    if (n <= 1 || n % 2 == 0)
    {
        return 0;
    }
    int divisor = 3;
    while (divisor <= sqrt((double)n))
    {
        if (n % divisor == 0)
        {
            return 0;
        }
        divisor += 2;
    }
    return 1;
}

void factor(int n)
{
    if (n <= 1 || isPrime(n))
    {
        printf("%d", n);
        return;
    }

    int primeFactor = 2;
    while (n != 1)
    {
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
        primeFactor++;
    }
}

int main(void)
{
    int n;
    printf("Entre um número inteiro: ");
    scanf("%d", &n);
    printf("%d = ", n);
    factor(n);
    return 0;
}