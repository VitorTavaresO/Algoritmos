#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (){
    int num[8];

    for(int i = 0; i < 8; i++){
        printf("Informe um valor para a posicao %d do vetor: ", i+1);
        scanf("%d", &num[i]);
    }

    for(int i = 0; i < 8; i++){
        if(num[i] % 6 == 0){
            printf("%d\n", num[i]);
        }
    }
    return 0;
}