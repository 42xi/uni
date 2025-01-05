#include <stdio.h>
#include <stdlib.h>
void GetArray(int n)
{
    int *array = malloc(n * sizeof(int));

    if (array == NULL)
    {
        printf("Fehler");
    }

    else

    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }

        printf("Ausgabe: \n");
        for (int j = 0; j < n; j++)
        {
            printf("%d\n", array[j]);
        }
    }

    free(array);
}

int main()
{
    int num;

    printf("Bitte Anzahl eingeben: ");
    scanf("%d", &num);

    GetArray(num);

    return 0;
}