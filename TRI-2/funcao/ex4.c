#include <stdio.h>

int sum(int inputA, int inputB){
    return inputA + inputB;
}

int main(){
    int inputA, inputB;
    printf("Digite um numero inteiro para A: ");
    scanf("%d", &inputA);
    printf("Digite um numero inteiro para B: ");
    scanf("%d", &inputB);
    printf("%d + %d = %d", inputA, inputB, sum(inputA, inputB));
}