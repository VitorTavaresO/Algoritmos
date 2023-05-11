#include <stdio.h>
#include <conio.h>
#include <string.h>

struct DadosAluno{
    char nomeAluno[100];
    int idadeAluno;
};

int main(){
    struct DadosAluno aluno1;
    printf("Digite o nome do aluno: ");
    scanf("%s", aluno1.nomeAluno);
    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno1.idadeAluno);

    printf("------------------------ \n");
    printf("Nome do aluno: %s \n", aluno1.nomeAluno);
    printf("Idade do aluno: %d \n", aluno1.idadeAluno);
}