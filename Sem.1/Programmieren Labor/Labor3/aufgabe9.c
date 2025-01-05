#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, c, n = 10;

    // scanf("%d", &n);

    for (i = 0; n > i; i++)
    {

        for (c = 0; c < n; c++)
        {
            if (i == 0 || i == n - 1 || c == 0 || c == n - 1 || i == c || i + c == n - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}