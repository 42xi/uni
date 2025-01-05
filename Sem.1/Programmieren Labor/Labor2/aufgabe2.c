#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Umrechnung von Fahrenheit auf Celsius
int main()
{
    // Variabln deffenieren und als Float scannen
    float fahrenheit, celsius;
    scanf("%f", &fahrenheit);

    // Umrechnung
    celsius = (5 * (fahrenheit - 32)) / 9;

    // Ausgabe
    printf("%.1f", fahrenheit);
    printf(" Grad Fahrenheit = %.1f", celsius);
    printf(" Grad Celsius");
    return 0;
}
