#include <stdio.h>

int num1, num2;

void calcularValor(int num1, int num2){
    printf("Funcao Valor");
    printf("\nSoma: %d\n", num1 + num2);
    printf("Multiplicacao: %d\n", num1 * num2);
}

void calcularReferencia(int *num1, int *num2){
    printf("\nFuncao Referencia");
    printf("\nSoma: %d\n", *num1 + *num2);
    printf("Multiplicacao: %d\n", *num1 * *num2);
}

void calcularSemParametro(){
    printf("\nFuncao Sem Parametro");
    printf("\nSoma: %d\n", num1 + num2);
    printf("Multiplicacao: %d\n", num1 * num2);
}

int main(){
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    calcularValor(num1, num2);
    calcularReferencia(&num1, &num2);
    calcularSemParametro();
    return 0;
}