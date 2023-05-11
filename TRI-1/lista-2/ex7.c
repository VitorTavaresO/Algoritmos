#include <stdio.h>
#include <conio.h>
#include <math.h>

int main (){
    float value[3], maior;
    for (int i = 0; i < 2; i++){
        printf("Insira o %d numero :", i + 1);
        scanf("%f", &value[i]);
    }

    maior = value[0];

    for (int i = 0; i < 2; i++){
        if(value[i] > maior){
            maior = value[i];
        }
    }

    printf("Maior = %f", maior);
}