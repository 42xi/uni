#include <stdio.h>

// Sie schreiben nur die Funktion, keine Ausgabe!
int prime(int p)
{
    if (p <= 1)
        return 0;

    for (int i = 2; i * i <= p; i++)
    {
        if (p % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    printf(prime(85) ? "Primzahl" : "KEINE Primzahl");
}