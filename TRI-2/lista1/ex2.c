#include <stdio.h>

int factorial (int input){
    int result = 1;
    for (int i = 1; i <= input; i++){
        result *= i;
    }
    return result;
}

int main(){
    int input;
    printf("Digite um numero inteiro: ");
    scanf("%d", &input);
    printf("O fatorial de %d eh %d", input, factorial(input));
    return 0;
}