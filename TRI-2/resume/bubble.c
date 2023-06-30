#include <stdio.h>
int numero[4] = {4, 2, 1, 3};
void main(void)
{
    int i, j, aux, n;
    for (i = 2; i >= 0; i--)
    {
        for (j = 0; j <= i; j++)
        {
            if (numero[j] > numero[j + 1])
            {
                aux = numero[j + 1];
                numero[j + 1] = numero[j];
                numero[j] = aux;
            }
        }
    }

    for (i = 0; i <= 3; i++)
    {
        printf("%d", numero[i]);
    }
}