#include <stdio.h>

int main()
{
    int vector[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &vector[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (vector[i] > vector[j])
            {
                int aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }

    int mid = 5 / 2;
    printf("%d", vector[mid]);
}