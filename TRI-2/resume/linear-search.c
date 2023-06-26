#include <stdio.h>
int numero[4] = {4, 2, 1, 3};

void main()
{
    int i, value;
    printf("Valor a ser buscado: ");
    scanf("%d", &value);
    for (i = 0; i <= 4; i++)
    {
        if (numero[i] == value)
        {
            printf("Valor encontrado na posicao %d", i);
            break;
        }
    }
}
