#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int main()
{
    clock_t start, end;

    double time_used;

    start = clock();

    readValues();

    end = clock();

    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f\n", time_used);

    return 0;
}