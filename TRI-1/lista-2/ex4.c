#include <stdio.h>
#include <conio.h>
#include <math.h>

int main (){
    float razao, primeiroT, quintoT;
    scanf("%f", &razao);
    scanf("%f", &primeiroT);
    quintoT = primeiroT * pow(razao, 4);
    printf("%f", quintoT);
}