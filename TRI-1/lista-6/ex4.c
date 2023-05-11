#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main (){
    int v[10], w[10];
    int i = 0;
    srand(time(NULL));

    while(i < 10){
        v[i] = rand() % 100;
        w[i] = v[i] * v[i];

        printf("Quadrado: %.2d\n", w[i]); 
        i++;
    }
    return 0;
}