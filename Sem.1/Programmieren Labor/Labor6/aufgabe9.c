
#include <stdio.h>

// Sie schreiben nur die Funktion, keine Ausgabe!
float celsius(float f)
{

    return (f - 32) / 1.8;
}
int main()
{
    printf("%dF = %.1fC", 20, celsius(20));
    return 0;
}