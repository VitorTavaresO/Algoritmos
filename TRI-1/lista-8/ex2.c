#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Cliente{
    char nome[100];
    int agencia;
    char dataNascimento[10];
    float saldo;
    char situacao[10];
};

int main (){
    struct Cliente cliente[2] = {
        {"Joao", 123, "01/01/2000", 10540.89, "VIP"},
        {"Maria", 123, "25/07/1998", 1010.80, "NORMAL"}
    };
    
    for (int i = 0; i < 2; i++){
        printf("Nome: %s \n", cliente[i].nome);
        printf("Agencia: %d \n", cliente[i].agencia);
        printf("Data de nascimento: %s \n", cliente[i].dataNascimento);
        printf("Saldo: %f \n", cliente[i].saldo);
        printf("Situacao: %s \n", cliente[i].situacao);
        printf("------------------------ \n");
    }

    return 0;
}