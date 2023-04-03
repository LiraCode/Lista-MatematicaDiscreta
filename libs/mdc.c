int mdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    mdc(b, a % b);
}