#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Aluno
{
    int aluno;
    int disc1;
    int disc2;
    int disc3;
    int disc4;
    int disc5;
    int ano;
};

int readValues()
{
    FILE *file;
    char *token;
    char line[100];

    file = fopen("dados.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        token = strtok(line, ";");
        while (token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, ";");
        }
    }

    fclose(file);
    return 0;
}

int countLine(int *qtdLine)
{
    FILE *file;
    char line[100];

    file = fopen("dados.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        *qtdLine += 1;
    }

    fclose(file);
    return 0;
}

int main()
{
    clock_t inicio, fim;
    double tempo_gasto;
    int qtdLine = 0;

    inicio = clock();

    readValues();
    countLine(&qtdLine);

    fim = clock();

    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %.6f segundos\n", tempo_gasto);
    printf("%d\n", qtdLine);

    return 0;
}