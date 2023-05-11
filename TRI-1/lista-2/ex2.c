#include <stdio.h>
#include <conio.h>
#include <math.h>

int main (){
    float catetoO, catetoA, hipotenusa;
    scanf("%f", &catetoO);
    scanf("%f", &catetoA);
    hipotenusa = sqrt(pow(catetoO, 2.0) + pow(catetoA, 2.0));
    printf("%f", hipotenusa);
}