#include <stdio.h>
int numero[4] = {4, 2, 1, 3};
void main()
{
    int i, j, x;
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (numero[j] < numero[i])
            {
                x = numero[j];
                numero[j] = numero[i];
                numero[i] = x;
            }
        }
    }

    for (i = 0; i <= 3; i++)
    {
        printf("%d", numero[i]);
    }
}
