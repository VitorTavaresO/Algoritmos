#include <stdio.h>

int main(){
    int somaIdade;
    float y, x;

    printf("Insira a soma das idades: ");
    scanf("%d", &somaIdade);

    y = somaIdade / 3;
    x = 1.33333*y;

    printf("Idade A = %.1f\n", x);
    printf("Idade B = %.1f\n", y);
    
    return 0;
}