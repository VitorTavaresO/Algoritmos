#include <stdio.h>

int higher(){
    int inputA, inputB;
    printf("Digite um numero inteiro para A: ");
    scanf("%d", &inputA);
    printf("Digite um numero inteiro para B: ");
    scanf("%d", &inputB);
    if (inputA > inputB){
        return printf("Maior Numero Eh %d", inputA);
    } else {
        return printf("Maior Numero Eh %d", inputB);
    }
}

int main(){
    higher();
    return 0;
}