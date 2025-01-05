#include <stdio.h>

int main(int argc, char *argv[])
{
    char Wort[40];
    int buchstabenZahl = 0;

    scanf("%s", Wort);

    // Zähle die Buchstaben im Wort
    for (int i = 0; Wort[i] != '\0'; i++)
    {
        if ((Wort[i] >= 'a' && Wort[i] <= 'z'))
        {
            buchstabenZahl++;
        }
    }

    printf("%d Kleinbuchstaben\n", buchstabenZahl);

    return 0;
}