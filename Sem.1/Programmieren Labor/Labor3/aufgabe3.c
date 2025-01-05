#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[])
{
    int h, b, i, c;

    scanf("%d %d", &h, &b);

    for (i = 0; h > i; i++)
    {

        for (c = 0; c < b; c++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
