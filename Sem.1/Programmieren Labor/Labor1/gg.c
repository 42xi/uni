#include <stdio.h>

int ff(int i, int j)
{
       printf("0, 1, ");
       for (int a = 0; a <= 10; a++)
       {
              int z = i + j;
              printf("%d, ", z);

              i = j;
              j = z;
       }
       return 0;
}

int main()
{
       int i = 0;
       int j = 1;

       ff(i, j);

       return 0;
}