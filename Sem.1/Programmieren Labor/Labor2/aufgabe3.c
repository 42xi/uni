#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// BMI RECHNUNG
int main()
{
    // Variabln deffenieren
    float große, BMI, großeM, gewichtKg, gewicht;

    // Eingabe scannen
    scanf("%f %f", &gewicht, &große);

    // UmRechnung
    gewichtKg = gewicht / 1000;
    großeM = große / 100;
    BMI = gewichtKg / (großeM * großeM);

    // Ausgabe
    printf("Der BMI liegt bei: %.2f", BMI);
    printf("!");

    // printf("%f\n", großeM);
    // printf("%f", gewichtKg);
    return 0;
}
