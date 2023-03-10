#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main (){
    int matrix[3][4], matrix2[3][4];
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            matrix2[i][j] = 3 * matrix[i][j];
                printf("%d, ",matrix2[i][j]);
        }
    }
    return 0;
}