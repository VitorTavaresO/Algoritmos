#include <stdio.h>

int main() {
    int numero1, numero2, quantidadeMultiplos;
    printf("Digite o primeiro numero a ser utilizado: ");
    scanf("%d", &numero1);
    printf("Digite o segundo numero a ser utilizado: ");
    scanf("%d", &numero2);
    printf("Digite o numero de multiplos simultaneos que deseja: ");
    scanf("%d", &quantidadeMultiplos);

    int count = 1;
    int i = 1;
    printf("Esses sao os multiplos em comum entre os numeros: \n");
    while (count <= quantidadeMultiplos) {
        if (i % numero1 == 0 && i % numero2 == 0) {
            printf("%d,", i);
            count++;
        }
        i++;
    }
    printf("\n");
    return 0;
}