#include <stdio.h>
int main(void) {
    char op;
    float num1, num2, res;
    scanf("%c %f %f", &op, &num1, &num2);
    if(op == '+') {
        res = num1 + num2;
    } else if(op == '-') {
        res = num1 - num2;
    } else if(op == '/') {
        res = num1 / num2;
    } else if(op == '*') {
        res = num1 * num2;
    }
    printf("%.2f", res);
    return 0;
}