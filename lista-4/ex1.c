#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (){
    int n1[5], n2[5], soma[5];

    for(int i = 0; i < 10; i++){
        if(i < 5){
            printf("Informe um valor para a posicao %d do vetor 1: ", i+1);
            scanf("%d", &n1[i]);
        } else{
            printf("Informe um valor para a posicao %d do vetor 2: ", (i -5)+1);
            scanf("%d", &n2[(i - 5)]);
        }
    }

    for(int i = 0; i < 5; i++){
        soma[i] = n1[i] + n2[i];
        printf("%d\n", soma[i]);
    }

    return 0;
}