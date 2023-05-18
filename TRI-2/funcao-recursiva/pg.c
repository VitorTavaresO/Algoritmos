#include <stdio.h>

int pg (int input, int first, int ratio){
    if(input == 1){
        return first;
    } else {
        return ratio * pg(input -1, first, ratio);
    }
}

int main (){
    int input, ratio;
    printf("Digite a posicao da pg: ");
    scanf("%d", &input);
    printf("Digite a razao: ");
    scanf("%d", &ratio);
    printf("O termo %d da PG eh %d", input, pg(input, 1, ratio));
    return 0;
}