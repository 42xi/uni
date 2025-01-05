#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, x, n;

    scanf("%d", &i);

    for (n = 0; i > n; i--)

    {
        x = i % 2;
        if (x == 0)

        {
            printf("_");
        }
        else
        {
            printf("*");
        }
    }

    return 0;
}
