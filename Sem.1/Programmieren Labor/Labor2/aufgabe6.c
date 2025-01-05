#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SPITZE 1
#define GUT 2
#define BEFRIEDIGEND 3
#define AUSREICHEND 4
#define DURCHGEFALLEN 5
#define JA 1
#define NEIN 0

// BESTANDEN ODER NICHT BESTANDEN
int main(void)
{
    // Variabln deffenieren
    unsigned int note, bestanden;
    printf("Geben Sie bitte eine Note (1-5) ein: ");

    // Note Eingabe scannen
    scanf("%u", &note);

    // Hier wird die Note geprüft ob es BESTANDEN ODER NICHT BESTANDEN ist
    switch (note)
    {
    case SPITZE:

    case GUT:

    case BEFRIEDIGEND:

    case AUSREICHEND:
        bestanden = JA;
        break;

    default:
        DURCHGEFALLEN;
        bestanden = NEIN;
    }
    // Ausgabe
    bestanden ? printf("\nOK!") : printf("\nNICHT bestanden");

    return 0;
}