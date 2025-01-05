#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int num1, num2;
    
    scanf("%d %d", &num1, &num2);
     printf("1. Zahl: 0x%x\n", num1);
     printf("2. Zahl: 0x%X\n", num2);
    
    return 0;
}
