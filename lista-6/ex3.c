#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main (){
    int matrix1[20], matrix2[20];
    int i, j;
    int flag = 0;
    srand(time(NULL));

    i = 0;

    while(i < 20){
        matrix1[i] = rand() % 100;
        matrix2[i] = rand() % 100;
        i++;
    }

    i = 0;
    while(i < 20){
        j = 0;
        while(j < 20){
            if(matrix1[i] == matrix2[j]){
                printf("O numero %d esta nas duas matrizes\n", matrix1[i]);
                flag = 1;
            }
            j++;
        }
        i++;
    }

    if(flag == 0)
        printf("Nao ha numeros repetidos nas duas matrizes\n");
    return 0;
}