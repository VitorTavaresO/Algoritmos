#include <stdio.h>

int main()
{
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = vector;
    printf("Elementos do Vetor: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *(ptr + i));
    }

    return 0;
}