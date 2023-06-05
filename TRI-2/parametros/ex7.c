#include <stdio.h>

void validateDate(int day, int month, int year, int *valid){
    if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1){
        *valid = 0;
    }else{
        *valid = 1;
    }
}

int main(){
    int day, month, year, valid;
    printf("Digite a data (Dia/Mes/Ano): ");
    scanf("%d/%d/%d", &day, &month, &year);
    validateDate(day, month, year, &valid);
    if(valid){
        if(month == 1){
            printf("%d de Janeiro de %d", day, year);
        }else if(month == 2){
            printf("%d de Fevereiro de %d", day, year);
        }else if(month == 3){
            printf("%d de Marco de %d", day, year);
        }else if(month == 4){
            printf("%d de Abril de %d", day, year);
        }else if(month == 5){
            printf("%d de Maio de %d", day, year);
        }else if(month == 6){
            printf("%d de Junho de %d", day, year);
        }else if(month == 7){
            printf("%d de Julho de %d", day, year);
        }else if(month == 8){
            printf("%d de Agosto de %d", day, year);
        }else if(month == 9){
            printf("%d de Setembro de %d", day, year);
        }else if(month == 10){
            printf("%d de Outubro de %d", day, year);
        }else if(month == 11){
            printf("%d de Novembro de %d", day, year);
        }else if(month == 12){
            printf("%d de Dezembro de %d", day, year);
        }
    }else{
        printf("Data invalida!");
    }
    return 0;
}