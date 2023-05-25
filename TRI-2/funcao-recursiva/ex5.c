#include <stdio.h>

int recursivePow(int base, int pow){
    if (pow == 0){
        return 1;
    } else {
        return base * recursivePow(base, pow - 1);
    }
}

int main(){
    int base, pow;
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &pow);
    printf("%d elevado a %d = %d", base, pow, recursivePow(base, pow));
    return 0;
}