#include <stdio.h>
#include <conio.h>
#include <math.h>

int main (){
    float razao, primeiroT, decimoT;
    scanf("%f", &razao);
    scanf("%f", &primeiroT);
    decimoT = primeiroT + 9 * razao;
    printf("%f", decimoT);
}