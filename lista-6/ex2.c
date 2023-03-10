#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (){
    float salary[20];
    int i = 0;

    while(i < 20){
        printf("Digite o salario do funcionario %d: ", i+1);
        scanf("%f", &salary[i]);
        i++;
    }

    i = 0;
    while(i < 20){
        salary[i] = salary[i] * 1.08;
        i++;
    }

    return 0;
}