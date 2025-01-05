#include <stdio.h>

int weekday(int d, int m, int y)
{
    if (m < 3)
        y = y - 1;

    return ((d + (int)(2.6 * ((m + 9) % 12 + 1) - 0.2) + y % 100 + (int)(y % 100 / 4) + (int)(y / 400) - 2 * (int)(y / 100) - 1) % 7 + 7) % 7;
}

int main()
{
    printf("%d", weekday(29, 4, 2021));
    return 0;
}