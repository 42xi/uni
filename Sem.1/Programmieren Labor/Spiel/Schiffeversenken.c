#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

void spielfeld(char feld[10][10])
{
    printf("  ABCDEFGHIJ\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%2d", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%c", feld[i][j]);
        }
        printf("\n");
    }
}

void schiffpositionen(char feld[10][10])
{
    printf("  ABCDEFGHIJ\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%2d", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%c", feld[i][j] == '#' ? '#' : '.');
        }
        printf("\n");
    }
}

void markiereFelder(char feld[10][10], char *eingabe)
{
    char startSpalte, endSpalte;
    int startZeile, endZeile;
    sscanf(eingabe, "%c%d-%c%d", &startSpalte, &startZeile, &endSpalte, &endZeile);
    int startSpalteIndex = startSpalte - 'A';
    int endSpalteIndex = endSpalte - 'A';

    for (int i = startZeile - 1; i < endZeile; i++)
    {
        for (int j = startSpalteIndex; j <= endSpalteIndex; j++)
        {
            feld[i][j] = '#';
        }
    }
}

int schiffLaenge(char feld[10][10], int zeile, int spalte, int richtung)
{
    int laenge = 0;
    if (richtung == 0)
    {
        for (int i = zeile; i < 10 && feld[i][spalte] != '.'; i++)
            if (feld[i][spalte] == '#' || feld[i][spalte] == 'X')
                laenge++;
        for (int i = zeile - 1; i >= 0 && feld[i][spalte] != '.'; i--)
            if (feld[i][spalte] == '#' || feld[i][spalte] == 'X')
                laenge++;
    }
    else
    {
        for (int j = spalte; j < 10 && feld[zeile][j] != '.'; j++)
            if (feld[zeile][j] == '#' || feld[zeile][j] == 'X')
                laenge++;
        for (int j = spalte - 1; j >= 0 && feld[zeile][j] != '.'; j--)
            if (feld[zeile][j] == '#' || feld[zeile][j] == 'X')
                laenge++;
    }
    return laenge;
}

int istSchiffVersenkt(char feld[10][10], int zeile, int spalte, int *laenge)
{
    *laenge = schiffLaenge(feld, zeile, spalte, 0);
    if (*laenge > 1)
    {
        for (int i = zeile; i < 10 && feld[i][spalte] != '.'; i++)
            if (feld[i][spalte] == '#')
                return 0;
        for (int i = zeile - 1; i >= 0 && feld[i][spalte] != '.'; i--)
            if (feld[i][spalte] == '#')
                return 0;
    }
    else
    {
        *laenge = schiffLaenge(feld, zeile, spalte, 1);
        if (*laenge > 1)
        {
            for (int j = spalte; j < 10 && feld[zeile][j] != '.'; j++)
                if (feld[zeile][j] == '#')
                    return 0;
            for (int j = spalte - 1; j >= 0 && feld[zeile][j] != '.'; j--)
                if (feld[zeile][j] == '#')
                    return 0;
        }
        else
        {
            *laenge = 1;
        }
    }
    return 1;
}

void schuesse(char feld[10][10], char schussListe[][60], int *anzahlSchuesse, int *treffer)
{
    char ein[10];

    for (int lim = 8; lim != 0; lim--)
    {
        scanf("%s", ein);
        if (ein[0] == 'x')
            break;

        char spalte;
        int zeile;
        if (sscanf(ein, "%c%d", &spalte, &zeile) != 2)
            break;
        int spalteIndex = spalte - 'A';
        if (zeile < 1 || zeile > 10 || spalteIndex < 0 || spalteIndex > 9)
            break;

        if (feld[zeile - 1][spalteIndex] == 'O' || feld[zeile - 1][spalteIndex] == 'X')
            break;

        if (feld[zeile - 1][spalteIndex] == '.')
        {
            feld[zeile - 1][spalteIndex] = 'O';
            sprintf(schussListe[*anzahlSchuesse], "%c%d Fehlschuss!", spalte, zeile);
        }
        else if (feld[zeile - 1][spalteIndex] == '#')
        {
            feld[zeile - 1][spalteIndex] = 'X';
            sprintf(schussListe[*anzahlSchuesse], "%c%d Getroffen!", spalte, zeile);
            (*treffer)++;

            int laenge;
            if (istSchiffVersenkt(feld, zeile - 1, spalteIndex, &laenge))
            {
                const char *typen[] = {"", "", " U-Boot", " Zerstörer", " Kreuzer", " Schlachtschiff"};
                strcat(schussListe[*anzahlSchuesse], typen[laenge]);
                strcat(schussListe[*anzahlSchuesse], " wurde versenkt!");
            }
        }
        (*anzahlSchuesse)++;
    }
}

void ausgabeSchussListe(char schussListe[][60], int anzahlSchuesse)
{
    for (int i = 0; i < anzahlSchuesse; i++)
    {
        printf("%s\n", schussListe[i]);
    }
    printf("\n");
}

int alleSchiffeVersenkt(char feld[10][10])
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (feld[i][j] == '#')
                return 0;
    return 1;
}

int main(int argc, char *argv[])
{
    char feld[10][10], originalFeld[10][10], schussListe[100][60];
    int anzahlSchuesse = 0, treffer = 0;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            feld[i][j] = '.';

    while (1)
    {
        char eingabe[20];
        scanf("%s", eingabe);
        if (eingabe[0] == 'e')
            break;
        markiereFelder(feld, eingabe);
    }

    memcpy(originalFeld, feld, sizeof(feld));
    schuesse(feld, schussListe, &anzahlSchuesse, &treffer);
    schiffpositionen(originalFeld);

    printf("\n");
    ausgabeSchussListe(schussListe, anzahlSchuesse);

    printf(alleSchiffeVersenkt(feld) ? "Alle Schiffe wurden versenkt\n\n" : "Das Spiel wurde beendet.\n\n");
    spielfeld(feld);
    printf("\n");

    if (anzahlSchuesse > 0)
        printf("Trefferquote: %.0lf%%\n", ((double)treffer / anzahlSchuesse) * 100.00);
    else
        printf("Trefferquote: 0%%\n");

    return 0;
}