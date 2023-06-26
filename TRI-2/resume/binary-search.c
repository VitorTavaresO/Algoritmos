#include <stdio.h>
int numero[4] = {1, 2, 3, 4};

void main()
{
    int i, value;
    printf("Valor a ser buscado: ");
    scanf("%d", &value);

    int left, right, middle;
    left = 0;
    right = 4;
    do
    {
        middle = (left + right) / 2;
        if (numero[middle] == value)
        {
            printf("Valor encontrado na posicao %d", middle);
            break;
        }
        else if (value > numero[middle])
        {
            left = middle + 1;
        }
        else if (value < numero[middle])
        {
            right = middle - 1;
        }
    } while (left <= right);
}
