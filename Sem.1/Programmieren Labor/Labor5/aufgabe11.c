#include <stdio.h>
int main()
{
    int value = 42;
    int *pointer = &value;

    printf("%d\n", value);
    value = 85;
    printf("%d\n", value);
    value++;
    printf("%d\n", *pointer);
    return 0;
}