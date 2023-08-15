#include <stdio.h>

int main()
{
    int num = 10;
    int *ptr;

    ptr = &num;

    printf("Valor de num: %d\n", num);
    printf("Endereco de num: %p\n", &num);
    printf("Valor apontado por ptr: %d\n", *ptr);
    printf("Endereco armazenado em: %p\n", ptr);

    return 0;
}