#include <stdio.h>
#include <conio.h>

int main ()
{
    float salario, salarionovo, reajuste;

    scanf("%f", &salario);
    scanf("%f", &reajuste);

    reajuste = reajuste/100;
    salarionovo = (reajuste*salario) + salario;

    printf("R$%.2f", salarionovo);
}