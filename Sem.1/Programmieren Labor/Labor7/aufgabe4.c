void append(char *a, char *b)
{
    // Gehe zu dem Ende von a
    while (*a != '\0')
    {
        a++;
    }

    // Kopiere die Zeichen von b an das Ende von a
    while (*b != '\0')
    {
        *a = *b;
        a++;
        b++;
    }

    // Setze das Endezeichen für die kombinierte Zeichenkette
    *a = '\0';
}