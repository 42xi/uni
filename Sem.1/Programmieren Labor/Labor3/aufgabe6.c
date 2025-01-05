#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Celsius Fahrenheit\n");

    int cel, fah;

    for (cel = -20; cel <= 300; cel = cel + 20)
    {
        fah = ((cel * 9) / 5) + 32;

        printf("%7d %10d\n", cel, fah);
    }
    return 0;
}
