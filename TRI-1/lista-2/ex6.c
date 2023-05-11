#include <stdio.h>
#include <conio.h>
#include <math.h>

int main (){
    float ladoA, ladoB, ladoC;
    scanf("%f", &ladoA);
    scanf("%f", &ladoB);
    scanf("%f", &ladoC);

    if(ladoA + ladoB > ladoC && ladoA + ladoC > ladoB && ladoB + ladoC > ladoA){
        if (ladoA == ladoB && ladoA == ladoC){
            printf("Equilatero");
        }
        else if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC){
            printf("Isosceles");
        }
        else{
            printf("Escaleno");
        }
    }
}