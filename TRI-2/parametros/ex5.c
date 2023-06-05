#include <stdio.h>

void somaBit(int b1, int b2, int *vaium, int *soma){
    *soma = b1 ^ b2 ^ *vaium;
    *vaium = (b1 & b2) | (b1 & *vaium) | (b2 & *vaium);
}

int main(){
    int b1, b2, vaium, soma;
    printf("Digite o primeiro bit: ");
    scanf("%d", &b1);
    printf("Digite o segundo bit: ");
    scanf("%d", &b2);
    printf("Digite o vai um: ");
    scanf("%d", &vaium);
    somaBit(b1, b2, &vaium, &soma);
    printf("Soma: %d\nVai um: %d", soma, vaium);
}