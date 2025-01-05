// Sie schreiben nur die Funktion, keine Ausgabe!
char *toUpper(char *wort)
{
    int i = 0;
    while (wort[i] != '\0')
    {
        if (wort[i] >= 'a' && wort[i] <= 'z')
        {
            wort[i] = wort[i] - 32;
        }
        i++;
    }
    return wort;
}