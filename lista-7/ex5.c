#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main (){
    int matrix[4][4], matrix2[4][4], sum[4][4];
    int i, j;


    printf("Digite os valores da primeira matriz: \n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Digite os valores da segunda matriz: \n");

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("A soma das duas matrizes e: \n");
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            sum[i][j] = matrix2[i][j] + matrix[i][j];
                printf("%d, ",sum[i][j]);
        }
    }
    return 0;
}