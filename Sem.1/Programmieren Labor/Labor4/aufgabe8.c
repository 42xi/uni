#include <stdio.h>

int main(int argc, char *argv[])
{
    float noten[10], sum = 0, d;
    int i;

    for (i = 0; i < 10; i++)
    {
        scanf("%f", &noten[i]);

        if (noten[i] >= 1 && noten[i] <= 6)
        {
            sum = sum + noten[i];
        }
        else
        {
            break;
        }
    }

    d = sum / i;

    if (i > 0)
    {
        printf("Durchschnitt (N=%d): %.2f", i, d);
    }
    else
    {
        printf("Durchschnitt (N=0): 0.00");
    }

    return 0;
}