#include <stdio.h>

int main(int argc, char *argv[])
{
    // Variblen Deklaration
    double Zahl[4];
    double KleinsteZahl;
    int Stelle = 0;

    // Array Wert Zahl[0] scannen und die Kleinste Zahl, Zahl[0] Zuweisen
    scanf("%lf", &Zahl[0]);
    KleinsteZahl = Zahl[0];

    // Array Werte abgesehen von Zahl[0] scannen
    for (int j = 1; j < 4; j++)
    {
        scanf("%lf", &Zahl[j]);

        if (Zahl[j] < KleinsteZahl)
        {
            // Verzweigung um Zahl[j] mit Zahl[0] zuvergleichen und zu ersetzen
            KleinsteZahl = Zahl[j];

            // Hier wird array stelle des kleinsten Zahls eingetragen
            Stelle = j;
        }
    }

    printf("Kleinste Zahl: %.1lf an Index %d", KleinsteZahl, Stelle);

    return 0;
}
