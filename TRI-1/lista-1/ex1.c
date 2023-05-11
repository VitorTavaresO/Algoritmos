#include <stdio.h>
#include <conio.h>


int main ()
{
    float raio, diametro, area, circunferencia;
    scanf("%f", &raio);

    diametro = 2*raio;
    area = 3.14159*(raio*raio);
    circunferencia = 2*3.14159*raio;

    printf("Diametro = %f\n", diametro);
    printf("Area = %f\n", area);
    printf("Circunferencia = %f", circunferencia);
}