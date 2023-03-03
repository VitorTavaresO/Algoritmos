#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (){
    int matrix[3][3];
    int input;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Informe um valor: ");
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Insira o multiplicador: ");
    scanf("%d", &input);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("O novo valor e: %d\n", matrix[i][j] * input);
        }
    }

    return 0;
}