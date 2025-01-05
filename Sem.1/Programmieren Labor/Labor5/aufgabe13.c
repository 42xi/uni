#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[])
{
    int arr[4];
    double d, sum = 0;

    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    d = sum / 4;

    printf("Summe: %.0lf\n", sum);
    printf("Durchschnitt: %lf", d);

    return 0;
}
