#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[])
{
    int arr[4];

    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int f = 0; f < 4; f++)
    {
        printf("%d ", arr[f]);
    }

    int *pointer = &arr[2];
    *pointer = 42;

    printf("\n");

    for (int j = 0; j < 4; j++)
    {
        printf("%d ", arr[j]);
    }

    return 0;
}
