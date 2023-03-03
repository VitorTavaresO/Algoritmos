#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {
    char nomes[10][50];
    float notas[10][4], media;

    for (int i = 0; i < 10; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", nomes[i]);

        for (int j = 0; j < 4; j++) {
            printf("Digite a nota %d do aluno: ", j + 1, i + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    for (int i = 0; i < 10; i++) {
        media = 0;
        printf("%s", nomes[i]);
        for (int j = 0; j < 4; j++) {
            media += notas[i][j];
        }

        media = media / 4;
        if (media < 6.0){
            printf(" | Reprovado\n");
        }else{
            printf(" | Aprovado\n");
        }
    }

    return 0;
}