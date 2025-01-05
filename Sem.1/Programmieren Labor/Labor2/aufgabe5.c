#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ALKOHUL IM BLUT IN PROZENT
int main()
{
    // Variabln Deffenieren
    char r;
    float W, A, masse, V, e, phi = 0.8;

    // Eingabe scannen
    scanf("%c %f %f %f", &r, &masse, &V, &e);

    // Umrechnung Aufgenommene Masse des Alkohols
    A = V * (e / 100) * phi;

    // If Else um die Rechnung zwischen Männer, Frauen und Kinder zu teilen
    if (r == 'm')
    {
        W = A / (masse * 0.7);
        printf("%.2f", W);
        printf(" Promille");
    }
    else if (r == 'w')
    {
        W = A / (masse * 0.6);
        printf("%.2f", W);
        printf(" Promille");
    }
    else if (r == 'k')
    {
        W = A / (masse * 0.8);
        printf("%.2f", W);
        printf(" Promille");
    }

    return 0;
}