#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= 200; i++)
    {
        if (i % n == 0 && i % m == 0)
        {
            printf("fizzbuzz\n");
        }
        else if (i % m == 0)
        {
            printf("buzz\n");
        }
        else if (i % n == 0)
        {
            printf("fizz\n");
        }
        else
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
