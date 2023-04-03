#include <stdio.h>
#include "libs/reverse.c"
#include "libs/mdc.c"

typedef struct CongruenceResult
{
    int nSolutions;
    int baseSolution;
    int m;
} CongruenceResult;

CongruenceResult evaluateCongruence(int a, int b, int m)
{
    int mdc_am = mdc(a, m);
    CongruenceResult result;
    if (mdc_am == 1)
    {
        result.nSolutions = 1;
        int inverse = getInverse(a, m);
        result.baseSolution = (inverse * b) % m;
        result.m = m;
    }
    else
    {
        if (b % mdc_am == 0)
        {
            CongruenceResult reducedResult = evaluateCongruence(
                a / mdc_am,
                b / mdc_am,
                m / mdc_am);

            result.nSolutions = mdc_am;
            result.baseSolution = reducedResult.baseSolution;
            result.m = reducedResult.m;
        }
        else
        {
            result.nSolutions = 0;
            result.baseSolution = 0;
        }
    }
    return result;
}

void printResults(CongruenceResult res)
{
    if (res.nSolutions == 0)
    {
        printf("A congruência não tem solução.");
        return;
    }
    for (int i = 0; i < res.nSolutions; i++)
    {
        printf("x%d = %d\n", i, res.baseSolution + i * res.m);
    }
}

int main(void)
{
    int a;
    int b;
    int m;
    printf("Entre três números inteiros (a, b e m): ");
    scanf("%d %d %d", &a, &b, &m);
    CongruenceResult res = evaluateCongruence(a, b, m);
    printResults(res);
    return 0;
}