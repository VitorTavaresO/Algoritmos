#include <stdio.h>
#include <conio.h>
#include <string.h>

struct DadosAluno{
    char nomeAluno[100];
    int idadeAluno;
};

int main(){
    struct DadosAluno aluno[10];
    for(int i = 0; i < 10; i++){
        printf("Digite o nome do aluno: ");
        scanf("%s", aluno[i].nomeAluno);
        printf("Digite a idade do aluno: ");
        scanf("%d", &aluno[i].idadeAluno);
    }
    printf("------------------------ \n");
    printf("Alunos Cadastrados: \n");
    for(int i = 0; i < 10; i++){
        printf("Nome do aluno: %s \n", aluno[i].nomeAluno);
        printf("Idade do aluno: %d \n", aluno[i].idadeAluno);
        printf("------------------------ \n");
    }
}