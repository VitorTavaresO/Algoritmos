#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (){
    float num[5];

    for(int i = 0; i < 5; i++){
        printf("Informe um valor de produto: ");
        scanf("%f", &num[i]);
    }

    for(int i = 0; i < 5; i++){
        num[i] += num[i] * 0.10;
        printf("%.2f\n", num[i]);
    }
    return 0;
}