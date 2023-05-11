#include <stdio.h>
#include <conio.h>
#include <math.h>

int main (){
    float value[5], menor;
    for (int i = 0; i < 5; i++){
        printf("Insira o %d numero :", i + 1);
        scanf("%f", &value[i]);
    }

    menor = value[0];

    for (int i = 0; i < 5; i++){
        if(value[i] < menor){
            menor = value[i];
        }
    }

    printf("Menor = %f", menor);
}