#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main (){
    int matrix[5][5];
    int i, j;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
                printf("%d\n", matrix[i][j]);
        }
    }
    return 0;
}