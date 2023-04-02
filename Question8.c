#include <stdio.h>

typedef struct LinearCombination
{
    int a;
    int b;
    int s;
    int t;
    int mdc;
} LinearCombination;

typedef struct CongruenceResult
{
    int nSolutions;
    int baseSolution;
    int m;
} CongruenceResult;

int mdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    mdc(b, a % b);
}

int _reverseEuclides(int a, int b, int *s, int *t, int *count)
{
    // Normal Euclides
    int mod = a % b;
    int div = a / b;
    if (mod == 0)
    {
        *s = 1;
        *t = 0;
        return b;
    }

    int mdc = _reverseEuclides(b, mod, s, t, count);

    // Update s and t values, after finding the mdc
    if (*count == 1)
    {
        *s = 1;
        *t = -div;
    }
    else if (*count % 2 == 0)
    {
        *s = *s + (*t) * (-div);
    }
    else
    {
        *t = *t + (*s) * (-div);
    }
    (*count)++;

    // DEBUG:
    // printf("%d %d %d %d (count=%d s=%d t=%d)\n", a, b, div, mod, *count, *s, *t);

    // Returns the mdc value
    return mdc;
}

/*
 * Higher Level function to find the Linear combination of a and b.
 *
 * a: integer
 * b: integer
 *
 * returns: LinearCombination struct (containing s, t and the mdc(a, b), where
 *         mdc(a, b) = s * a + t * b).

*/
LinearCombination reverseEuclides(int a, int b)
{
    int count = 1;
    LinearCombination comb;
    comb.s = 0;
    comb.t = 0;
    comb.a = a;
    comb.b = b;

    if (a > b)
    {
        comb.mdc = _reverseEuclides(a, b, &(comb.s), &(comb.t), &count);
        if (count % 2 != 0)
        {
            int tmp = comb.s;
            comb.s = comb.t;
            comb.t = tmp;
        }
    }
    else
    {

        comb.mdc = _reverseEuclides(b, a, &(comb.s), &(comb.t), &count);
        if (count % 2 == 0)
        {
            int tmp = comb.s;
            comb.s = comb.t;
            comb.t = tmp;
        }
    }

    return comb;
}

int getInverse(int a, int m)
{
    LinearCombination comb = reverseEuclides(a, m);
    int inverse;
    if (comb.s < 0)
    {
        inverse = comb.s + m;
    }
    else
    {
        inverse = comb.s;
    }
    return inverse;
}

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
        printf("Congruence does not have a Solution!");
        return;
    }
    for (int i = 0; i < res.nSolutions; i++)
    {
        printf("x%d = %d\n", i, res.baseSolution + i * res.m);
    }
}

int main(void)
{
    int a = 4;
    int b = 8;
    int m = 20;
    CongruenceResult res = evaluateCongruence(a, b, m);
    printResults(res);
    return 0;
}