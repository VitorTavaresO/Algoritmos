#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void generateMatrix(int **matrix, int lines, int columns, int min, int max){
    int i, j;
    for(i = 0; i < lines; i++){
        for(j = 0; j < columns; j++){
            matrix[i][j] = rand() % (max + 1 - min) + min;
        }
    }
}

void biggestSmallestAndMedia(int **matrix, int lines, int columns, int *biggest, int *smallest, double *media){
    int i, j, sum = 0;
    *biggest = matrix[0][0];
    *smallest = matrix[0][0];
    for(i = 0; i < lines; i++){
        for(j = 0; j < columns; j++){
            sum += matrix[i][j];
            if(matrix[i][j] > *biggest){
                *biggest = matrix[i][j];
            }
            if(matrix[i][j] < *smallest){
                *smallest = matrix[i][j];
            }
        }
    }
    *media = (double) sum / (lines * columns);
}

int main(){
    int lines, columns, min, max;
    printf("Digite o numero de linhas: ");
    scanf("%d", &lines);
    printf("Digite o numero de colunas: ");
    scanf("%d", &columns);
    printf("Digite o valor minimo: ");
    scanf("%d", &min);
    printf("Digite o valor maximo: ");
    scanf("%d", &max);
    int **matrix = malloc(lines * sizeof(int *));
    int i;
    for(i = 0; i < lines; i++){
        matrix[i] = malloc(columns * sizeof(int));
    }
    generateMatrix(matrix, lines, columns, min, max);
    for(i = 0; i < lines; i++){
        int j;
        for(j = 0; j < columns; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    int biggest, smallest;
    double media;
    biggestSmallestAndMedia(matrix, lines, columns, &biggest, &smallest, &media);
    printf("Maior: %d\n", biggest);
    printf("Menor: %d\n", smallest);
    printf("Media: %.2lf\n", media);
    return 0;
}

