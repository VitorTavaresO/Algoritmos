#include <stdio.h>

int pa (int input, int first, int ratio){
    if(input == 1){
        return first;
    } else {
        return ratio + pa(input -1, first, ratio);
    }
}

int main (){
    int input, ratio;
    printf("Digite qual termo da pa quer saber: ");
    scanf("%d", &input);
    printf("Digite a razao da pa: ");
    scanf("%d", &ratio);
    printf("O termo %d da PG eh %d", input, pa(input, 1, ratio));
    return 0;
}