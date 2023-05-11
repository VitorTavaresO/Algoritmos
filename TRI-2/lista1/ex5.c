#include <stdio.h>

float media(float prova1, float prova2, float prova3){
    return (prova1 + prova2 + prova3) / 3;
}

int main(){
    float prova1, prova2, prova3;
    printf("Digite a nota da primeira prova: ");
    scanf("%f", &prova1);
    printf("Digite a nota da segunda prova: ");
    scanf("%f", &prova2);
    printf("Digite a nota da terceira prova: ");
    scanf("%f", &prova3);
    printf("A media das notas eh: %f", media(prova1, prova2, prova3));
    return 0;
}