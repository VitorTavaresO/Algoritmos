#include <stdio.h>

int changePosition(int inputA, int inputB){
    int aux = inputA;
    inputA = inputB;
    inputB = aux;
    return printf("A: %d\nB: %d", inputA, inputB);
}

int main(){
    int inputA, inputB;
    printf("Digite um numero inteiro para A: ");
    scanf("%d", &inputA);
    printf("Digite um numero inteiro para B: ");
    scanf("%d", &inputB);
    changePosition(inputA, inputB);
    return 0;
}

