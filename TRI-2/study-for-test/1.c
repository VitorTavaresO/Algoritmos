#include <stdio.h>

int bubbleSort(int vector[])
{
    int i, j, aux;
    for (i = 8; i >= 0; i--)
    {
        for (j = 0; j <= i; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}

int binarySearch(int vector[], int value)
{
    int left, right, middle;
    left = 0;
    right = 10;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (vector[middle] == value)
        {
            printf("Valor encontrado na posicao %d", middle);
            break;
        }
        else if (value > vector[middle])
        {
            left = middle + 1;
        }
        else if (value < vector[middle])
        {
            right = middle - 1;
        }
    }
}

int main()
{
    int vector[10] = {8, 2, 6, 1, 9, 5, 3, 10, 4, 7};
    int i, value;
    bubbleSort(vector);
    for (i = 0; i <= 9; i++)
    {
        printf("%d", vector[i]);
    }
    printf("Informe um valor a ser buscado: ");
    scanf("%d", &value);
}