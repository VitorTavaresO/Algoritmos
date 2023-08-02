#include <stdio.h>

int main()
{
    int matrix[3][3], sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Sintoma %d", j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += matrix[i][j];
        }
        if (sum == 3)
        {
            printf("Paciente %d tem os 3 sintomas", i + 1);
        }
        sum = 0;
    }
}