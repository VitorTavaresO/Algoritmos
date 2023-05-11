#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (){
    int num[15];

    for(int i = 0; i < 15; i++){
        printf("Informe um valor para a posicao %d do vetor: ", i+1);
        scanf("%d", &num[i]);
    }

    for(int i = 0; i < 15; i++){
        if(num[i] % 2 == 0){
            printf("O numero %d e par\n", num[i]);
        }else{
            printf("O numero %d e impar\n", num[i]);
        }
    }
    return 0;
}