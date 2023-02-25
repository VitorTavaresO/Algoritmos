#include <stdio.h>
#include <conio.h>

int main()
{
    float primeiroNumero, segundoNumero, media;

    scanf("%f", &primeiroNumero);
    scanf("%f", &segundoNumero);

    media = (primeiroNumero + segundoNumero)/2;

    printf("%f", media);
}