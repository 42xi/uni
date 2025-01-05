#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
    int erg = a + b;

    return erg;
}

void result(int r)
{
    printf("%d", r);
}

int main()
{
    int i = 5;
    int f = 5;

    int g = add(i, f);
    result(g);

    return 0;
}