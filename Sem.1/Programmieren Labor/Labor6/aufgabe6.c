#include <stdio.h>

int stringlength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int main()
{
    char test[] = "Hochschule Esslingen";
    printf("%s hat %d Zeichen\n", test, stringlength(test));

    return 0;
}
