#include <stdio.h>

int main(){
    int array[10] = {2,4,35,50,23,17,9,12,27,5};
    float sum;
    int higher = array[0];
    int aux;
    int primo;

    for (int i = 0; i < 10; i++){
        sum += array[i];
    }
    float media = sum / 10;
    printf("Media = %.2f", media);
    printf("\n");

    for (int i = 0; i < 10; i++){
        if (array[i] > higher){
            higher = array[i];
        }
    }
    printf("Maior valor = %d", higher);
    printf("\n");


    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (array[i] < array[j]){
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }

    printf("Ordem crescente: ");
    for (int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Conjunto dos numeros primos: \n{");
    for (int i = 0; i < 10; i++){
        primo = 1;
        for (int j = 2; j < array[i]; j++){
            if (array[i] % j == 0){
                primo = 0;
                break;
            }
        }
        if(primo == 1 && array[i] > 1){
            printf("%d,", array[i]);
        }
    }
    printf("}");

    return 0;
}