#include <stdio.h>

void sumBit(int b1, int b2, int *goOne, int *sum){
    *sum = b1 ^ b2 ^ *goOne;
    *goOne = (b1 & b2) | (b1 & *goOne) | (b2 & *goOne);
}

int main(){
    int b1, b2, goOne, sum;
    printf("Digite o primeiro bit: ");
    scanf("%d", &b1);
    printf("Digite o segundo bit: ");
    scanf("%d", &b2);
    printf("Digite o vai um: ");
    scanf("%d", &goOne);
    sumBit(b1, b2, &goOne, &sum);
    printf("Soma: %d\nVai um: %d", sum, goOne);
}