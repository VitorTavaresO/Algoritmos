#include <stdio.h>
#include <conio.h>

int main ()
{
    float numerador, denominador, resultado;

    scanf("%f", &numerador);
    scanf("%f", &denominador);

    while (denominador == 0){
            printf("Valor Invalido, insira um novo valor: \n");
            scanf("%f", &denominador);
        }
        resultado = numerador / denominador;
        printf("%f", resultado);
}