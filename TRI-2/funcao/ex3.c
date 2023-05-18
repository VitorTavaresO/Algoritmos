#include <stdio.h>

int higher(){
    int inputA, inputB;
    printf("Digite um numero inteiro para A: ");
    scanf("%d", &inputA);
    printf("Digite um numero inteiro para B: ");
    scanf("%d", &inputB);
    if (inputA > inputB){
        return printf("Numeros em Ordem Crescente: %d, %d", inputB, inputA);
    } else {
        return printf("Numeros em Ordem Crescente: %d, %d", inputA, inputB);
    }
}

int main(){
    higher();
    return 0;
}