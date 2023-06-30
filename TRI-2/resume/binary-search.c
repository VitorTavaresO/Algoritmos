#include <stdio.h>

void main()
{
    int numero[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, value;
    printf("Valor a ser buscado: ");
    scanf("%d", &value);
    int left, right, middle;
    left = 0;
    right = 10;
    while (left <= right)
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
    }
}
