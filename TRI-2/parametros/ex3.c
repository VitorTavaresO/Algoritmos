#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void generateVector(int *vector, int size, int min, int max){
    int i;
    for(i = 0; i < size; i++){
        vector[i] = rand() % (max + 1 - min) + min;
    }
}

void biggestAndSmallest(int *vector, int size, int *biggest, int *smallest){
    int i;
    *biggest = vector[0];
    *smallest = vector[0];
    for(i = 0; i < size; i++){
            if(vector[i] > *biggest){
                *biggest = vector[i];
            }
            if(vector[i] < *smallest){
                *smallest = vector[i];
        }
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
    int biggest, smallest;
    biggestAndSmallest(vector, size, &biggest, &smallest);
    printf("\nMaior: %d\n", biggest);
    printf("Menor: %d\n", smallest);
    return 0;
}