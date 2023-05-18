#include <stdio.h>

int factorial(int input){
    if(input == 0){
        return 1;
    } else {
        return input * factorial(input-1);
    }
}

int main(){
    int input;
    printf("Digite um numero inteiro: ");
    scanf("%d", &input);
    printf("O fatorial de %d eh %d", input, factorial(input));
    return 0;
}