#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int num1;
    float num2;
    char zeichen;
    
    scanf("%d %f %c", &num1, &num2, &zeichen);
    
    printf("Ganzzahlen    : %010d\n", num1);
    printf("Gleitkommazahl: %.5f\n", num2);
    printf("Zeichen       : %c\n", zeichen);
    return 0;
}
