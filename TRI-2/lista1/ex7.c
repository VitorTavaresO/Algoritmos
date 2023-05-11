#include <stdio.h>

int even(int input){
    if (input % 2 == 0){
        return printf("O numero eh par");
    } else {
        return printf("O numero eh impar");
    }
}

int main(){
    int input;
    printf("Digite um numero inteiro: ");
    scanf("%d", &input);
    even(input);
    return 0;
}
