#include <stdio.h>

void modifyValue(int *x)
{
    *x += 10;
}

int main()
{
    int num = 5;
    printf("Antes da modificacao: %d\n", num);
    modifyValue(&num);
    printf("Depois da modificacao: %d\n", num);
    return 0;
}