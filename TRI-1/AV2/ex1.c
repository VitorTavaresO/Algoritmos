#include <stdio.h>

int main(){
    int matrix[5][5];
    int i, j;

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("Digite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matriz: \n");
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}