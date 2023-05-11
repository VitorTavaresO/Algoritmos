#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main (){
    int v[30];
    int i = 0;
    srand(time(NULL));

    while(i < 30){
        v[i] = rand() % 100;
        printf("%d\n", v[i]);
        i++;
    }

    printf("--------------------\n");

    for(i = 29; i >=0; i--){
        printf("%d\n", v[i]);
    }
    return 0;
}