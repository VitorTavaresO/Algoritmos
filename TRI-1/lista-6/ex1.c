#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (){
    int numbers[10];
    int i = 0;

    while(i < 10){
        printf("Digite um numero: ");
        scanf("%d", &numbers[i]);
        i++;
    }

    i = 0;
    while(i < 10){
        printf("%d. %d\n", i+1, numbers[i]);
        i++;
    }

    return 0;
}