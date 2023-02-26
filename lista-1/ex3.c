#include <stdio.h>
#include <conio.h>

int main ()
{
    float celsius, fahrenheit;

    scanf("%f", &celsius);

    fahrenheit = celsius*1.8 + 32;

    printf("Fahrenheit %f", fahrenheit);
}