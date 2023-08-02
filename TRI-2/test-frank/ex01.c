#include <stdio.h>

int main()
{
    float vector[5], sum = 0, average = 0, summation = 0, variance = 0;
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Insira a %d altura \n", i + 1);
        scanf("%f", &vector[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        sum += vector[i];
    }

    average = sum / 5;

    for (int i = 0; i < 5; i++)
    {
        summation += (vector[i] - average) * (vector[i] - average);
    }

    variance = summation / 5;
    printf("%f", variance);
}