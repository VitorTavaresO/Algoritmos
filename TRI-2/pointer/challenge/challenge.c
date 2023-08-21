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

void readValues(int *rowNumbers)
{
    //------------------------------- READ FILE -------------------------------//
    FILE *file;
    char line[100];
    file = fopen("dados.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        *rowNumbers += 1;
    }

    //------------------------------- WRITE STRUCT -------------------------------//

    rewind(file);
    struct Student student[*rowNumbers];
    int i = 0;
    while (
        fscanf(file, "%d;%d;%d;%d;%d;%d;%d", &student[i].student, &student[i].disc1, &student[i].disc2, &student[i].disc3, &student[i].disc4, &student[i].disc5, &student[i].ano) == 7)
    {
        printf("student: %d\n", student[i].student);
        printf("Disciplina 1: %d\n", student[i].disc1);
        printf("Disciplina 2: %d\n", student[i].disc2);
        printf("Disciplina 3: %d\n", student[i].disc3);
        printf("Disciplina 4: %d\n", student[i].disc4);
        printf("Disciplina 5: %d\n", student[i].disc5);
        printf("Ano: %d\n", student[i].ano);
        i++;
    }
    //------------------------------- WRITE STRUCT -------------------------------//
}
int main()
{
    clock_t start, end;
    double time_spent;
    int rowNumbers = 0;

    start = clock();
    readValues(&rowNumbers);

    end = clock();

    time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %.6f segundos\n", time_spent);
    printf("%d\n", rowNumbers);

    return 0;
}