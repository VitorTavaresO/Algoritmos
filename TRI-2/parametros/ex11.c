#include <stdio.h>

void calculatePoints(int golsTimeA, int golsTimeB, int *pontosTimeA, int *pontosTimeB){
    if(golsTimeA > golsTimeB){
        *pontosTimeA = *pontosTimeA + 3;
    }else if(golsTimeA < golsTimeB){
        *pontosTimeB = *pontosTimeB + 3;
    }else{
        *pontosTimeA = *pontosTimeA + 1;
        *pontosTimeB = *pontosTimeB + 1;
    }
}

int main(){
    int pontosTimeA, pontosTimeB, golsTimeA, golsTimeB;
    pontosTimeA = 12;
    pontosTimeB = 7;
    printf("Digite os gols do time A: ");
    scanf("%d", &golsTimeA);
    printf("Digite os gols do time B: ");
    scanf("%d", &golsTimeB);
    calculatePoints(golsTimeA, golsTimeB, &pontosTimeA, &pontosTimeB);
    printf("Pontos do time A: %d\n", pontosTimeA);
    printf("Pontos do time B: %d\n", pontosTimeB);
    return 0;
}