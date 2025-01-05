#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Fahrenheit");
    printf("      Celsius\n");

    float fah;
    float cel;

    for (fah = -20; fah <= 300; fah = fah + 20)
    {
        cel = ((fah - 32) * 5) / 9;

        printf("%10.0f %12.2f\n", fah, cel);
    }
    return 0;
}
