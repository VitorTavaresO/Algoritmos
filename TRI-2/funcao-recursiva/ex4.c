#include <stdio.h>

int somaDigitos (int input){
    if(input < 10){
        return input;
    } else {
        return input % 10 + somaDigitos(input / 10);
    }
}51

int main (){
    int input;
    printf("Digite um numero: ");
    scanf("%d", &input);
    printf("A soma dos digitos de %d eh %d", input, somaDigitos(input));
    return 0;
}

