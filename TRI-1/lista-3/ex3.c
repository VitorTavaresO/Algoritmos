#include <stdio.h>
#include <conio.h>

int main ()
{
    float nota1, nota2, media;

    scanf("%f", &nota1);

    while (nota1 < 0  || nota1 > 10){
            printf("Nota 1 Invalida, insira uma nova nota: \n");
            scanf("%f", &nota1);
        }

    scanf("%f", &nota2);
    
    while (nota2 < 0  || nota2 > 10){
            printf("Nota 2 Invalida, insira uma nova nota: \n");
            scanf("%f", &nota2);
        }
        media = (nota1 + nota2) / 2.0;
        printf("%f", media);
}