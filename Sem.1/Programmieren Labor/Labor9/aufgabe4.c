#include <stdio.h>
#include <stdlib.h>

// Definition der Struktur für ein Listenelement
typedef struct numberItem
{
    int value;               // Der Wert, den das Listenelement speichert
    struct numberItem *next; // Zeiger auf das nächste Listenelement
} numberItem;

// Funktion zum Anhängen einer Zahl an die Liste
void append(numberItem **root, int value)
{
    // Speicher für ein neues Listenelement allokieren
    numberItem *newItem = (numberItem *)malloc(sizeof(numberItem));
    if (!newItem) // Überprüfen, ob die Speicherallokation erfolgreich war
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    newItem->value = value; // Den Wert des neuen Listenelements setzen
    newItem->next = NULL;   // Das neue Element zeigt auf kein weiteres Element (da es das letzte ist)

    if (*root == NULL) // Überprüfen, ob die Liste leer ist
    {
        *root = newItem; // Wenn ja, wird das neue Element zum Wurzelelement
    }
    else // Wenn die Liste nicht leer ist
    {
        numberItem *current = *root;
        // Bis zum letzten Element der Liste durchlaufen
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newItem; // Das neue Element am Ende der Liste anfügen
    }
}

// Funktion zum Ausgeben aller Elemente der Liste
void print(numberItem *root)
{
    numberItem *current = root;
    // Solange das aktuelle Element nicht NULL ist
    while (current != NULL)
    {
        printf("%d\n", current->value); // Den Wert des aktuellen Elements ausgeben
        current = current->next;        // Zum nächsten Element übergehen
    }
}

// Funktion zum Leeren der Liste und Freigeben des Speichers
void clear(numberItem **root)
{
    numberItem *current = *root;
    // Solange das aktuelle Element nicht NULL ist
    while (current != NULL)
    {
        numberItem *next = current->next; // Zeiger auf das nächste Element sichern
        free(current);                    // Speicher des aktuellen Elements freigeben
        current = next;                   // Zum nächsten Element übergehen
    }
    *root = NULL; // Die Wurzel der Liste auf NULL setzen (Liste ist jetzt leer)
}

int main()
{
    numberItem *root = NULL; // Initialisieren der Wurzel der Liste mit NULL (leere Liste)

    // Einige Zahlen an die Liste anhängen
    append(&root, 42);
    append(&root, 1);
    append(&root, 2);
    append(&root, 3);

    // Alle Elemente der Liste ausgeben
    print(root);

    // Die Liste leeren und den Speicher freigeben
    clear(&root);

    return 0; // Programm beenden
}
