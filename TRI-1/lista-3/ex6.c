#include <stdio.h>
#include <conio.h>

int main ()
{
    float valor, input, media;
    valor = 0;
    for (int i = 0; i < 10; i++){
            scanf("%f", &input);
            valor += input;
        }
    media = valor / 10.0;
    printf("%f", media);
    
}