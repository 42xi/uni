#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char wort[40];
    int zahl1, zahl2;

    scanf("%s %d %d", wort, &zahl1, &zahl2);

    printf("%s %d-%d: ", wort, zahl1, zahl2);

    for (int j = zahl1; j <= zahl2; j++)
    {
        printf("%c", wort[j]);
    }

    return 0;
}