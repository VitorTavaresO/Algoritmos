#include <stdio.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    int matrixA[5][5];
    int matrixB[5][5];
    int matrixSum[5][5];
    int matrixMult[5][5];
    int sumDiagonalA = 0;
    int sumDiagonalB = 0;
    int i, j;

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            matrixA[i][j] = rand() % 50;
        }
    }

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            matrixB[i][j] = rand() % 50;
        }
    }

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            matrixMult[i][j] = matrixA[i][j] * matrixB[i][j];
        }
    }

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if (i == j){
                sumDiagonalA += matrixA[i][j];
                sumDiagonalB += matrixB[i][j];
            }
        }
    }

    printf("Matriz A: \n");
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("Matriz B: \n");

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    printf("Matriz soma: \n");
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("%d ", matrixSum[i][j]);
        }
        printf("\n");
    }

    printf("Matriz multiplicacao: \n");
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("%d ", matrixMult[i][j]);
        }
        printf("\n");
    }

    printf("Soma diagonal A: %d", sumDiagonalA);
    printf("\n");
    printf("Soma diagonal B: %d", sumDiagonalB);


}