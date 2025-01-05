#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char wort[40];
    int length = 0;

    scanf("%s", wort);

    for (int i = 0; wort[i] != '\0'; i++)
    {
        length++;
    }

    for (int j = length; j >= 0; j--)
    {
        printf("%c", wort[j]);
    }
    return 0;
}