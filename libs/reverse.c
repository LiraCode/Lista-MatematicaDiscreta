#include <stdio.h>

typedef struct LinearCombination
{
    int a;
    int b;
    int s;
    int t;
    int mdc;
} LinearCombination;

int _reverseEuclides(int a, int b, int *s, int *t, int *count)
{
    int mod = a % b;
    int div = a / b;
    if (mod == 0)
    {
        *s = 1;
        *t = 0;
        return b;
    }

    int mdc = _reverseEuclides(b, mod, s, t, count);

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

    return mdc;
}

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