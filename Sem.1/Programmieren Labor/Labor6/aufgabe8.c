#include <stdio.h>

float bmi(float kg, float zm)
{
    return kg / ((zm / 100) * (zm / 100));
}

int main()
{
    printf("%dkg und %fm = %.2lf", 85, 1.5, bmi(85, 150));

    return 0;
}
