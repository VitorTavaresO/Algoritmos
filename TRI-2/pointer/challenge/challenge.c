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
    int j;
    struct Student aux;
    while (
        fscanf(file, "%d;%d;%d;%d;%d;%d;%d", &student[i].student, &student[i].disc1, &student[i].disc2, &student[i].disc3, &student[i].disc4, &student[i].disc5, &student[i].year) == 7)
    {
        i++;
    }
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

void ex01(int *rowNumbers, struct Student student[*rowNumbers])
{
    int i = 0;
    while (i < *rowNumbers)
    {
        int currentYear = student[i].year;
        int yearCount = 0;
        float average[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
        float medianDisc1[*rowNumbers];
        float medianDisc2[*rowNumbers];
        float medianDisc3[*rowNumbers];
        float medianDisc4[*rowNumbers];
        float medianDisc5[*rowNumbers];

        while (student[i].year == currentYear)
        {
            average[0] += student[i].disc1;
            average[1] += student[i].disc2;
            average[2] += student[i].disc3;
            average[3] += student[i].disc4;
            average[4] += student[i].disc5;

            medianDisc1[yearCount] = student[i].disc1;
            medianDisc2[yearCount] = student[i].disc2;
            medianDisc3[yearCount] = student[i].disc3;
            medianDisc4[yearCount] = student[i].disc4;
            medianDisc5[yearCount] = student[i].disc5;

            i++;
            yearCount++;
        }

        // Média
        float avg1 = average[0] / yearCount;
        float avg2 = average[1] / yearCount;
        float avg3 = average[2] / yearCount;
        float avg4 = average[3] / yearCount;
        float avg5 = average[4] / yearCount;

        printf("Ano: %d\n", currentYear);
        printf("Media disciplina 1: %.2f\n", avg1);
        printf("Media disciplina 2: %.2f\n", avg2);
        printf("Media disciplina 3: %.2f\n", avg3);
        printf("Media disciplina 4: %.2f\n", avg4);
        printf("Media disciplina 5: %.2f\n", avg5);
        printf("\n");

        // Ordenação para Mediana
        int j;
        for (j = 0; i < yearCount; i++)
        {
            for (j = i + 1; j < yearCount; j++)
            {
                if (medianDisc1[i] > medianDisc1[j])
                {
                    float aux = medianDisc1[i];
                    medianDisc1[i] = medianDisc1[j];
                    medianDisc1[j] = aux;
                }
                if (medianDisc2[i] > medianDisc2[j])
                {
                    float aux = medianDisc2[i];
                    medianDisc2[i] = medianDisc2[j];
                    medianDisc2[j] = aux;
                }
                if (medianDisc3[i] > medianDisc3[j])
                {
                    float aux = medianDisc3[i];
                    medianDisc3[i] = medianDisc3[j];
                    medianDisc3[j] = aux;
                }
                if (medianDisc4[i] > medianDisc4[j])
                {
                    float aux = medianDisc4[i];
                    medianDisc4[i] = medianDisc4[j];
                    medianDisc4[j] = aux;
                }
                if (medianDisc5[i] > medianDisc5[j])
                {
                    float aux = medianDisc5[i];
                    medianDisc5[i] = medianDisc5[j];
                    medianDisc5[j] = aux;
                }
            }
        }

        if (yearCount % 2 == 0)
        {
            printf("Mediana disciplina 1: %.2f\n", (medianDisc1[yearCount / 2] + medianDisc1[(yearCount / 2) - 1]) / 2);
            printf("Mediana disciplina 2: %.2f\n", (medianDisc2[yearCount / 2] + medianDisc2[(yearCount / 2) - 1]) / 2);
            printf("Mediana disciplina 3: %.2f\n", (medianDisc3[yearCount / 2] + medianDisc3[(yearCount / 2) - 1]) / 2);
            printf("Mediana disciplina 4: %.2f\n", (medianDisc4[yearCount / 2] + medianDisc4[(yearCount / 2) - 1]) / 2);
            printf("Mediana disciplina 5: %.2f\n", (medianDisc5[yearCount / 2] + medianDisc5[(yearCount / 2) - 1]) / 2);
            printf("\n");
        }
        else
        {
            printf("Mediana disciplina 1: %.2f\n", medianDisc1[yearCount / 2]);
            printf("Mediana disciplina 2: %.2f\n", medianDisc2[yearCount / 2]);
            printf("Mediana disciplina 3: %.2f\n", medianDisc3[yearCount / 2]);
            printf("Mediana disciplina 4: %.2f\n", medianDisc4[yearCount / 2]);
            printf("Mediana disciplina 5: %.2f\n", medianDisc5[yearCount / 2]);
            printf("\n");
        }

        float var1, var2, var3, var4, var5;
        for (j = 0; j < yearCount; j++)
        {
            var1 += pow((medianDisc1[j] - avg1), 2);
            var2 += pow((medianDisc2[j] - avg2), 2);
            var3 += pow((medianDisc3[j] - avg3), 2);
            var4 += pow((medianDisc4[j] - avg4), 2);
            var5 += pow((medianDisc5[j] - avg5), 2);
        }

        float stdDev1 = sqrt(var1 / yearCount);
        float stdDev2 = sqrt(var2 / yearCount);
        float stdDev3 = sqrt(var3 / yearCount);
        float stdDev4 = sqrt(var4 / yearCount);
        float stdDev5 = sqrt(var5 / yearCount);

        printf("Desvio padrao disciplina 1: %.2f\n", stdDev1);
        printf("Desvio padrao disciplina 2: %.2f\n", stdDev2);
        printf("Desvio padrao disciplina 3: %.2f\n", stdDev3);
        printf("Desvio padrao disciplina 4: %.2f\n", stdDev4);
        printf("Desvio padrao disciplina 5: %.2f\n", stdDev5);
        printf("\n");

        // Reset vetor média
        average[0] = 0.0;
        average[1] = 0.0;
        average[2] = 0.0;
        average[3] = 0.0;
        average[4] = 0.0;
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

    printf("Media da Primeira Disciplina: %.2f\n", avg1);
    printf("Media da Segunda Disciplina: %.2f\n", avg2);
    printf("Media da Terceira Disciplina: %.2f\n", avg3);
    printf("Media da Quarta Disciplina: %.2f\n", avg4);
    printf("Media da Quinta Disciplina: %.2f\n", avg5);
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
                float aux = medianDisc1[i];
                medianDisc1[i] = medianDisc1[j];
                medianDisc1[j] = aux;
            }
            if (medianDisc2[i] > medianDisc2[j])
            {
                float aux = medianDisc2[i];
                medianDisc2[i] = medianDisc2[j];
                medianDisc2[j] = aux;
            }
            if (medianDisc3[i] > medianDisc3[j])
            {
                float aux = medianDisc3[i];
                medianDisc3[i] = medianDisc3[j];
                medianDisc3[j] = aux;
            }
            if (medianDisc4[i] > medianDisc4[j])
            {
                float aux = medianDisc4[i];
                medianDisc4[i] = medianDisc4[j];
                medianDisc4[j] = aux;
            }
            if (medianDisc5[i] > medianDisc5[j])
            {
                float aux = medianDisc5[i];
                medianDisc5[i] = medianDisc5[j];
                medianDisc5[j] = aux;
            }
        }
    }

    if (*rowNumbers % 2 == 0)
    {
        printf("Mediana da Primeira Disciplina %.2f\n", (medianDisc1[(*rowNumbers / 2) - 1] + medianDisc1[(*rowNumbers / 2)]) / 2);
        printf("Mediana da Segunda Disciplina %.2f\n", (medianDisc2[(*rowNumbers / 2) - 1] + medianDisc2[(*rowNumbers / 2)]) / 2);
        printf("Mediana da Terceira Disciplina %.2f\n", (medianDisc3[(*rowNumbers / 2) - 1] + medianDisc3[(*rowNumbers / 2)]) / 2);
        printf("Mediana da Quarta Disciplina %.2f\n", (medianDisc4[(*rowNumbers / 2) - 1] + medianDisc4[(*rowNumbers / 2)]) / 2);
        printf("Mediana da Quinta Disciplina %.2f\n", (medianDisc5[(*rowNumbers / 2) - 1] + medianDisc5[(*rowNumbers / 2)]) / 2);
    }
    else
    {
        printf("Mediana da Primeira Disciplina %.2f\n", medianDisc1[(*rowNumbers / 2)]);
        printf("Mediana da Segunda Disciplina %.2f\n", medianDisc2[(*rowNumbers / 2)]);
        printf("Mediana da Terceira Disciplina %.2f\n", medianDisc3[(*rowNumbers / 2)]);
        printf("Mediana da Quarta Disciplina %.2f\n", medianDisc4[(*rowNumbers / 2)]);
        printf("Mediana da Quinta Disciplina %.2f\n", medianDisc5[(*rowNumbers / 2)]);
    }

    // Desvio padrão
    float var1, var2, var3, var4, var5;
    for (i = 0; i < *rowNumbers; i++)
    {
        var1 += pow((student[i].disc1 - avg1), 2);
        var2 += pow((student[i].disc2 - avg2), 2);
        var3 += pow((student[i].disc3 - avg3), 2);
        var4 += pow((student[i].disc4 - avg4), 2);
        var5 += pow((student[i].disc5 - avg5), 2);
    }

    float stdDeviaton1 = sqrt(var1 / (*rowNumbers));
    float stdDeviaton2 = sqrt(var2 / (*rowNumbers));
    float stdDeviaton3 = sqrt(var3 / (*rowNumbers));
    float stdDeviaton4 = sqrt(var4 / (*rowNumbers));
    float stdDeviaton5 = sqrt(var5 / (*rowNumbers));

    printf("\n");
    printf("Desvio Padrao da Primeira Disciplina: %.2f\n", stdDeviaton1);
    printf("Desvio Padrao da Segunda Disciplina: %.2f\n", stdDeviaton2);
    printf("Desvio Padrao da Terceira Disciplina: %.2f\n", stdDeviaton3);
    printf("Desvio Padrao da Quarta Disciplina: %.2f\n", stdDeviaton4);
    printf("Desvio Padrao da Quinta Disciplina: %.2f\n", stdDeviaton5);
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

    printf("Aprovados na Primeira Disciplina: %d\n", disc1);
    printf("Aprovados na Segunda Disciplina: %d\n", disc2);
    printf("Aprovados na Terceira Disciplina: %d\n", disc3);
    printf("Aprovados na Quarta Disciplina: %d\n", disc4);
    printf("Aprovados na Quinta Disciplina: %d\n", disc5);
    printf("\n");

    disc1 = *rowNumbers - disc1;
    disc2 = *rowNumbers - disc2;
    disc3 = *rowNumbers - disc3;
    disc4 = *rowNumbers - disc4;
    disc5 = *rowNumbers - disc5;

    printf("Reprovados na Primeira Disciplina: %d\n", disc1);
    printf("Reprovados na Segunda Disciplina: %d\n", disc2);
    printf("Reprovados na Terceira Disciplina: %d\n", disc3);
    printf("Reprovados na Quarta Disciplina: %d\n", disc4);
    printf("Reprovados na Quinta Disciplina: %d\n", disc5);
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

    file = fopen("dados.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
    }

    countFileLines(&rowNumbers, file);

    struct Student student[rowNumbers];

    readValues(&rowNumbers, file, student);

    printf("-----------------------\n");
    printf("Media, mediana e desvio padrao por ano: \n");
    ex01(&rowNumbers, student);

    printf("-----------------------\n");
    printf("Media, mediana e desvio padrao: \n");
    ex02(&rowNumbers, student);

    printf("-----------------------\n");
    printf("Melhor e pior desempenho: \n");
    ex03(&rowNumbers, student);

    printf("-----------------------\n");
    printf("Total de aprovados e reprovados: \n");
    ex04(&rowNumbers, student);

    fclose(file);

    ex05(&rowNumbers, student);

    end = clock();

    time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %.6f segundos\n", time_spent);
    printf("%d\n", rowNumbers);

    return 0;
}