// Sie schreiben nur die Funktion, keine Ausgabe!
void ownStrcpy(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}