#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct Student
{
    int student;
    int disc1;
    int disc2;
    int disc3;
    int disc4;
    int disc5;
    int year;
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
        fscanf(file, "%d;%d;%d;%d;%d;%d;%d", &student[i].student, &student[i].disc1, &student[i].disc2, &student[i].disc3, &student[i].disc4, &student[i].disc5, &student[i].year) == 7)
    {
        i++;
    }
}

void sortedStruct(int *rowNumbers, struct Student student[*rowNumbers])
{
    int i, j;
    struct Student aux;
    for (i = 0; i < *rowNumbers; i++)
    {
        for (j = i + 1; j < *rowNumbers; j++)
        {
            if (student[i].year > student[j].year)
            {
                aux = student[i];
                student[i] = student[j];
                student[j] = aux;
            }
        }
    }
}

float calculateAveragePerYear(int *rowNumbers, struct Student student[*rowNumbers])
{
    int i;
    int minYear = student[0].year;
    int maxYear = student[0].year;
    for (i = 0; i < *rowNumbers; i++)
    {
        if (student[i].year < minYear)
        {
            minYear = student[i].year;
        }
        else if (student[i].year > maxYear)
        {
            maxYear = student[i].year;
        }
    }
    int j;
    float average[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
    int count = 0;
    i = minYear;
    while (i <= maxYear)
    {
        for (j = 0; j < *rowNumbers; j++)
        {
            if (student[j].year == i)
            {
                average[0] += student[j].disc1;
                average[1] += student[j].disc2;
                average[2] += student[j].disc3;
                average[3] += student[j].disc4;
                average[4] += student[j].disc5;
                count++;
            }
        }
        printf("year: %d\n", i);
        printf("Media Disciplina 1: %.2f\n", average[0] / count);
        printf("Media Disciplina 2: %.2f\n", average[1] / count);
        printf("Media Disciplina 3: %.2f\n", average[2] / count);
        printf("Media Disciplina 4: %.2f\n", average[3] / count);
        printf("Media Disciplina 5: %.2f\n", average[4] / count);
        average[0] = 0.0;
        average[1] = 0.0;
        average[2] = 0.0;
        average[3] = 0.0;
        average[4] = 0.0;
        count = 0;
        i++;
    }
}

float calculateMedianPerYear(int *rowNumbers, struct Student student[*rowNumbers])
{
    int i;
    int minYear = student[0].year;
    int maxYear = student[0].year;
    for (i = 0; i < *rowNumbers; i++)
    {
        if (student[i].year < minYear)
        {
            minYear = student[i].year;
        }
        else if (student[i].year > maxYear)
        {
            maxYear = student[i].year;
        }
    }

    for (i = minYear; i <= maxYear; i++)
    {
        int j;
        int count = 0;
        for (j = 0; j < *rowNumbers; j++)
        {
            if (student[j].year == i)
            {
                count++;
            }
        }
    }
}

void ex02(int *rowNumbers, struct Student student[*rowNumbers])
{
    int i;
    float average[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
    // Médias
    for (i = 0; i < *rowNumbers; i++)
    {
        average[0] += student[i].disc1;
        average[1] += student[i].disc2;
        average[2] += student[i].disc3;
        average[3] += student[i].disc4;
        average[4] += student[i].disc5;
    }

    float avg1 = average[0] / (*rowNumbers);
    float avg2 = average[1] / (*rowNumbers);
    float avg3 = average[2] / (*rowNumbers);
    float avg4 = average[3] / (*rowNumbers);
    float avg5 = average[4] / (*rowNumbers);

    printf("Media disciplina 1: %.2f\n", avg1);
    printf("Media disciplina 2: %.2f\n", avg2);
    printf("Media disciplina 3: %.2f\n", avg3);
    printf("Media disciplina 4: %.2f\n", avg4);
    printf("Media disciplina 5: %.2f\n", avg5);
    printf("\n");

    // Mediana
    float medianDisc1[*rowNumbers];
    float medianDisc2[*rowNumbers];
    float medianDisc3[*rowNumbers];
    float medianDisc4[*rowNumbers];
    float medianDisc5[*rowNumbers];

    for (i = 0; i < *rowNumbers; i++)
    {
        medianDisc1[i] = student[i].disc1;
        medianDisc2[i] = student[i].disc2;
        medianDisc3[i] = student[i].disc3;
        medianDisc4[i] = student[i].disc4;
        medianDisc5[i] = student[i].disc5;
    }

    for (i = 0; i < *rowNumbers; i++)
    {
        int j;
        for (j = i + 1; j < *rowNumbers; j++)
        {
            if (medianDisc1[i] > medianDisc1[j])
            {
                float temp = medianDisc1[i];
                medianDisc1[i] = medianDisc1[j];
                medianDisc1[j] = temp;
            }
            if (medianDisc2[i] > medianDisc2[j])
            {
                float temp = medianDisc2[i];
                medianDisc2[i] = medianDisc2[j];
                medianDisc2[j] = temp;
            }
            if (medianDisc3[i] > medianDisc3[j])
            {
                float temp = medianDisc3[i];
                medianDisc3[i] = medianDisc3[j];
                medianDisc3[j] = temp;
            }
            if (medianDisc4[i] > medianDisc4[j])
            {
                float temp = medianDisc4[i];
                medianDisc4[i] = medianDisc4[j];
                medianDisc4[j] = temp;
            }
            if (medianDisc5[i] > medianDisc5[j])
            {
                float temp = medianDisc5[i];
                medianDisc5[i] = medianDisc5[j];
                medianDisc5[j] = temp;
            }
        }
    }

    if (*rowNumbers % 2 == 0)
    {
        printf("Mediana disciplina 1: %.2f\n", (medianDisc1[(*rowNumbers / 2) - 1] + medianDisc1[(*rowNumbers / 2)]) / 2);
        printf("Mediana disciplina 2: %.2f\n", (medianDisc2[(*rowNumbers / 2) - 1] + medianDisc2[(*rowNumbers / 2)]) / 2);
        printf("Mediana disciplina 3: %.2f\n", (medianDisc3[(*rowNumbers / 2) - 1] + medianDisc3[(*rowNumbers / 2)]) / 2);
        printf("Mediana disciplina 4: %.2f\n", (medianDisc4[(*rowNumbers / 2) - 1] + medianDisc4[(*rowNumbers / 2)]) / 2);
        printf("Mediana disciplina 5: %.2f\n", (medianDisc5[(*rowNumbers / 2) - 1] + medianDisc5[(*rowNumbers / 2)]) / 2);
    }
    else
    {
        printf("Mediana disciplina 1: %.2f\n", medianDisc1[(*rowNumbers / 2)]);
        printf("Mediana disciplina 2: %.2f\n", medianDisc2[(*rowNumbers / 2)]);
        printf("Mediana disciplina 3: %.2f\n", medianDisc3[(*rowNumbers / 2)]);
        printf("Mediana disciplina 4: %.2f\n", medianDisc4[(*rowNumbers / 2)]);
        printf("Mediana disciplina 5: %.2f\n", medianDisc5[(*rowNumbers / 2)]);
    }

    // Desvio padrão
    float var1, var2, var3, var4, var5;
    for (i = 0; i < *rowNumbers; i++)
    {
        var1 += (student[i].disc1 - avg1) * (student[i].disc1 - avg1);
        var2 += (student[i].disc2 - avg2) * (student[i].disc2 - avg2);
        var3 += (student[i].disc3 - avg3) * (student[i].disc3 - avg3);
        var4 += (student[i].disc4 - avg4) * (student[i].disc4 - avg4);
        var5 += (student[i].disc5 - avg5) * (student[i].disc5 - avg5);
    }

    float stdDeviaton1 = sqrt(var1 / (*rowNumbers));
    float stdDeviaton2 = sqrt(var2 / (*rowNumbers));
    float stdDeviaton3 = sqrt(var3 / (*rowNumbers));
    float stdDeviaton4 = sqrt(var4 / (*rowNumbers));
    float stdDeviaton5 = sqrt(var5 / (*rowNumbers));

    printf("\n");
    printf("Desvio padrao Disciplina 1: %.2f\n", stdDeviaton1);
    printf("Desvio padrao Disciplina 2: %.2f\n", stdDeviaton2);
    printf("Desvio padrao Disciplina 3: %.2f\n", stdDeviaton3);
    printf("Desvio padrao Disciplina 4: %.2f\n", stdDeviaton4);
    printf("Desvio padrao Disciplina 5: %.2f\n", stdDeviaton5);
}

void ex03(int *rowNumbers, struct Student student[*rowNumbers])
{
    int i;
    float average[*rowNumbers];
    for (i = 0; i < *rowNumbers; i++)
    {
        average[i] = (student[i].disc1 + student[i].disc2 + student[i].disc3 + student[i].disc4 + student[i].disc5) / 5.0;
    }

    for (i = 0; i < *rowNumbers; i++)
    {
        printf("\nMedia do aluno %d: %.2f\n", i + 1, average[i]);
    }

    int bestStudent = 0;
    int worstStudent = 0;
    int bestAverage = average[0];
    int worstAverage = average[0];

    for (i = 0; i < *rowNumbers; i++)
    {
        if (bestAverage < average[i])
        {
            bestAverage = average[i];
            bestStudent = student[i].student;
        }
        if (worstAverage > average[i])
        {
            worstAverage = average[i];
            worstStudent = student[i].student;
        }
    }
    printf("\n");
    printf("Melhor aluno: %d\n", bestStudent);
    printf("Pior aluno: %d\n", worstStudent);
}

void ex04(int *rowNumbers, struct Student student[*rowNumbers])
{
    printf("Total de alunos: %d\n", *rowNumbers);

    int i;
    int disc1 = 0, disc2 = 0, disc3 = 0, disc4 = 0, disc5 = 0;
    for (i = 0; i < *rowNumbers; i++)
    {
        if (student[i].disc1 >= 70)
        {
            disc1++;
        }
        if (student[i].disc2 >= 70)
        {
            disc2++;
        }
        if (student[i].disc3 >= 70)
        {
            disc3++;
        }
        if (student[i].disc4 >= 70)
        {
            disc4++;
        }
        if (student[i].disc5 >= 70)
        {
            disc5++;
        }
    }

    printf("Aprovados disciplina 1: %d\n", disc1);
    printf("Aprovados disciplina 2: %d\n", disc2);
    printf("Aprovados disciplina 3: %d\n", disc3);
    printf("Aprovados disciplina 4: %d\n", disc4);
    printf("Aprovados disciplina 5: %d\n", disc5);
    printf("\n");

    disc1 = *rowNumbers - disc1;
    disc2 = *rowNumbers - disc2;
    disc3 = *rowNumbers - disc3;
    disc4 = *rowNumbers - disc4;
    disc5 = *rowNumbers - disc5;

    printf("Reprovados disciplina 1: %d\n", disc1);
    printf("Reprovados disciplina 2: %d\n", disc2);
    printf("Reprovados disciplina 3: %d\n", disc3);
    printf("Reprovados disciplina 4: %d\n", disc4);
    printf("Reprovados disciplina 5: %d\n", disc5);
}

void ex05(int *rowNumbers, struct Student student[*rowNumbers])
{
    FILE *sortedFile;
    sortedFile = fopen("ordenados.txt", "w");
    int i = 0;
    for (i = 0; i < *rowNumbers; i++)
    {
        fprintf(sortedFile, "%d;%d;%d;%d;%d;%d;%d\n", student[i].student, student[i].disc1, student[i].disc2, student[i].disc3, student[i].disc4, student[i].disc5, student[i].year);
    }
}
int main()
{
    clock_t start, end;
    double time_spent;
    start = clock();

    int rowNumbers;
    FILE *file;
    float average[5] = {0.0, 0.0, 0.0, 0.0, 0.0};

    file = fopen("dados.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
    }

    countFileLines(&rowNumbers, file);

    struct Student student[rowNumbers];

    readValues(&rowNumbers, file, student);

    sortedStruct(&rowNumbers, student);

    ex02(&rowNumbers, student);

    ex03(&rowNumbers, student);

    ex04(&rowNumbers, student);

    ex05(&rowNumbers, student);

    fclose(file);

    end = clock();

    time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %.6f segundos\n", time_spent);
    printf("%d\n", rowNumbers);

    return 0;
}