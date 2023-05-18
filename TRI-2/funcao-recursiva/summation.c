#include <stdio.h>

int summation (int n){
    if(n == 1){
        return 1;
    } else {
        return n + summation(n-1);
    }
}

int main(){
    int input;
    printf("Digite um numero de casas a ser somado a 1: ");
    scanf("%d", &input);
    printf("A somatoria : %d", summation(input));
}

