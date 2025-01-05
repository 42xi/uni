#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// BMI RECHNUNG MIT KOMMENTAR
int main()
{

    // Variabln deffenieren
    float große, BMI, großeM, gewichtKg, gewicht;

    // Eingabe gewicht und große scannen
    scanf("%f %f", &gewicht, &große);

    // Umrechnung
    gewichtKg = gewicht / 1000;
    großeM = große / 100;
    BMI = gewichtKg / (großeM * großeM);

    // If Else um Kommentare zu Ordnen und aus zu geben
    if (BMI <= 18.4)
    {
        printf("Untergewicht %.1f", BMI);
    }
    else if (BMI > 18.4 && BMI < 24.9)
    {
        printf("Normalgewicht %.1f", BMI);
    }
    else if (BMI >= 24.9)
    {
        printf("Uebergewicht %.1f", BMI);
    }

    return 0;
}
