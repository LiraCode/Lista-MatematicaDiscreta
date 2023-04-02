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
    // Normal Euclides
    int mod = a % b;
    int div = a / b;
    if (mod == 0)
    {
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

void printCombination(LinearCombination c)
{
    printf("%d = (%d) * %d + (%d) * %d\n", c.mdc, c.s, c.a, c.t, c.b);
}

int main(void)
{
    int a = 77;
    int b = 3;
    LinearCombination result = reverseEuclides(a, b);
    printCombination(result);
    return 0;
}