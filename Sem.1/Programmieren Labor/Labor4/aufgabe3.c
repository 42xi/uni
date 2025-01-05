#include <stdio.h>

int main(int argc, char *argv[])
{
    //
    char Wort[40];
    int buchstabenZahl = 0;

    scanf("%s", Wort);

    // Zähle die Buchstaben im Wort
    for (int i = 0; Wort[i] != '\0'; i++)
    {
        if (Wort[i] == 'a' || Wort[i] == 'e' || Wort[i] == 'i' || Wort[i] == 'o' || Wort[i] == 'u' || Wort[i] == 'A' || Wort[i] == 'E' || Wort[i] == 'I' || Wort[i] == 'O' || Wort[i] == 'U')
        {
            buchstabenZahl++;
        }
    }

    printf("%d Vokale\n", buchstabenZahl);

    return 0;
}