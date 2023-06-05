#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void generateVector(int *vector, int size, int min, int max){
    int i;
    for(i = 0; i < size; i++){
        vector[i] = rand() % (max + 1 - min) + min;
    }
}

void invertVector(int *vector, int size){
    int i, aux;
    for(i = 0; i < size / 2; i++){
        aux = vector[i];
        vector[i] = vector[size - 1 - i];
        vector[size - 1 - i] = aux;
    }
}

int main(){
    int size, min, max;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);
    printf("Digite o valor minimo: ");
    scanf("%d", &min);
    printf("Digite o valor maximo: ");
    scanf("%d", &max);
    int vector[size];
    generateVector(vector, size, min, max);
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", vector[i]);
    }
    invertVector(vector, size);
    printf("\n");
    for(i = 0; i < size; i++){
        printf("%d ", vector[i]);
    }
}