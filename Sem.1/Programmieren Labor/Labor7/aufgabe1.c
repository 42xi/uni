// Sie schreiben nur die Funktion, keine Ausgabe!
int minimum(int *num, int length)
{

    int minimum = num[0];

    for (int i = 1; i < length; i++)
    {
        if (num[i] < minimum)
        {
            minimum = num[i];
        }
    }
    return minimum;
}
