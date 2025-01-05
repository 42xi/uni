#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[])
{
    int h = 5, b = 5, i, c;

    // scanf("%d %d", &h, &b);

    for (i = 0; h > i; i++)
    {

        for (c = 0; c < b; c++)
        {

            if ((i + c) % 2 == 0)
            {
                printf("+");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}