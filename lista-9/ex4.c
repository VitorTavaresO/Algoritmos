#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Livro{
    char nome[100];
    char editora[100];
    int isbn;
    int ano;
    int numeroPaginas;
    float preco;
};

int main(){
    float media = 0;
    struct Livro livro[5];
    for(int i = 0; i < 5; i++){
        printf("Digite o nome do livro: ");
        scanf("%s", livro[i].nome);
        printf("Digite a editora do livro: ");
        scanf("%s", livro[i].editora);
        printf("Digite o ISBN do livro: ");
        scanf("%d", &livro[i].isbn);
        printf("Digite o ano do livro: ");
        scanf("%d", &livro[i].ano);
        printf("Digite o numero de paginas do livro: ");
        scanf("%d", &livro[i].numeroPaginas);
        printf("Digite o preco do livro: ");
        scanf("%f", &livro[i].preco);
    }
    printf("------------------------ \n");
    printf("Media de Paginas dos Livros: \n");
    for(int i = 0; i < 5; i++){
        media = media + livro[i].numeroPaginas;
    }
    printf("Media: %2.f \n", media/5);
}