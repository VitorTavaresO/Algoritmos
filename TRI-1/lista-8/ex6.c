#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Cliente{
    char nome[100];
    int ip;
    int plano;
    float valor;
    char situacao[1];
};

int main() {
    struct Cliente cliente[3];

    for (int i = 0; i < 3; i++){
        printf("Digite o nome do cliente: ");
        scanf("%s", &cliente[i].nome);
        printf("Digite o ip do cliente: ");
        scanf("%d", &cliente[i].ip);
        printf("Digite o plano do cliente: ");
        scanf("%d", &cliente[i].plano);
        printf("Digite o valor do plano: ");
        scanf("%f", &cliente[i].valor);
        printf("Digite a situacao do cliente: ");
        scanf("%s", &cliente[i].situacao);
        printf("------------------------ \n");
    }

    for (int i = 0; i < 3; i++){
        printf("Nome: %s \n", cliente[i].nome);
        printf("IP: %d \n", cliente[i].ip);
        if(cliente[i].plano == 1){
            printf("Plano: Ilimitado\n");
        }
        else if(cliente[i].plano ==2){
            printf("Plano: 20 horas/mes\n");
        } else{
            printf("Plano: 10 horas/mes\n");
        }
        printf("Valor: %2.f \n", cliente[i].valor);
        if(strcmp(cliente[i].situacao, "A") == 0){
            printf("Situacao: Ativo\n");
        }
        else{
            printf("Situacao: Inativo\n");
        }
        printf("------------------------ \n");
    }
}