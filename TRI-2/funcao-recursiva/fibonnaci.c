#include <stdio.h>

int fibonacci(int input){
    if(input == 0){
        return 0;
    } else if(input == 1){
        return 1;
    } else{
        return fibonacci(input-2) + fibonacci(input-1); 
    }
}

int main(){
    int input;
    printf("Digite um numero inteiro: ");
    scanf("%d", &input);
    printf("O fibonacci de %d eh %d", 5, fibonacci(input));
    return 0;
}