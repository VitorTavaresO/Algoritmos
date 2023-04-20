#include <stdio.h>

int main(){
    int input = 0;
    int higherNum = 0;
    scanf("%d", &input);

    for (int i = 2; i < input; i++){
        int prime = 1;
        for (int j = 2; j < i; j++){
            if (i % j == 0){
                prime = 0;
            }
        }
        if(prime == 1 && i > 1){
            higherNum = i;
        }
    }

     printf("%d", higherNum);

    return 0;
}