#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Student
{
    int student;
    int disc1;
    int disc2;
    int disc3;
    int disc4;
    int disc5;
    int ano;
};

void countFileLines(int *rowNumbers, FILE *file)
{
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        *rowNumbers += 1;
    }
}

void readValues(int *rowNumbers, FILE *file, struct Student student[*rowNumbers])
{
    rewind(file);
    int i = 0;
    while (
        fscanf(file, "%d;%d;%d;%d;%d;%d;%d", &student[i].student, &student[i].disc1, &student[i].disc2, &student[i].disc3, &student[i].disc4, &student[i].disc5, &student[i].ano) == 7)
    {
        i++;
    }
}

float calculateAverage(int *rowNumbers, struct Student student[*rowNumbers])
{
    int i;
    int minYear = student[0].ano;
    int maxYear = student[0].ano;
    for (i = 0; i < *rowNumbers; i++)
    {
        if (student[i].ano < minYear)
        {
            minYear = student[i].ano;
        }
        else if (student[i].ano > maxYear)
        {
            maxYear = student[i].ano;
        }
    }
}
int main()
{
    clock_t start, end;
    double time_spent;
    start = clock();

    int rowNumbers;
    FILE *file;

    file = fopen("dadosTest.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
    }

    countFileLines(&rowNumbers, file);

    struct Student student[rowNumbers];

    readValues(&rowNumbers, file, student);
    fclose(file);

    calculateAverage(&rowNumbers, student);

    end = clock();

    time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %.6f segundos\n", time_spent);
    printf("%d\n", rowNumbers);

    return 0;
}