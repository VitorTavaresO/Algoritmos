#include <stdio.h>
#include <math.h>

void changeValues(int *num1, int *num2){
    int aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}

void decrementAndIncrement(int *num1, int *num2){
    *num1 = *num1 - 1;
    *num2 = *num2 + 1;
}

void circlePerimeterAndArea(double *ray, double *perimeter, double *area ){
    *perimeter = 2 * 3.14 * *ray;
    *area = 3.14 * (*ray * *ray);
}

void squarePerimeterAndArea(double *side, double *perimeter, double *area){
    *perimeter = 4 * *side;
    *area = *side * *side;
}

void secondDegreeEquation(double a, double b, double c,  double *x1, double *x2){
    double delta = (b * b) - (4 * a * c);
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
}

int main(){
    int num1, num2;
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    changeValues(&num1, &num2);
    printf("Primeiro numero(Invertido): %d\n", num1);
    printf("Segundo numero(Invertido): %d\n", num2);
    decrementAndIncrement(&num1, &num2);
    printf("Primeiro numero (Incrementado): %d\n", num1);
    printf("Segundo numero (Decrementado): %d\n", num2);

    double ray, circlePerimeter, circleArea;
    printf("Digite o raio: ");
    scanf("%lf", &ray);
    circlePerimeterAndArea(&ray, &circlePerimeter, &circleArea);
    printf("Perimetro: %.2lf\n", circlePerimeter);
    printf("Area: %.2lf\n", circleArea);

    double side, squarePerimeter, squareArea;
    printf("Digite o tamanho lado: ");
    scanf("%lf", &side);
    squarePerimeterAndArea(&side, &squarePerimeter, &squareArea);
    printf("Perimetro: %.2lf\n", squarePerimeter);
    printf("Area: %.2lf\n", squareArea);

    double a, b, c, x1, x2;
    printf("ax^2 + bx + c = 0\n");
    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    printf("Digite o valor de b: ");
    scanf("%lf", &b);
    printf("Digite o valor de c: ");
    scanf("%lf", &c);
    secondDegreeEquation(a, b, c, &x1, &x2);
    printf("x1: %.2lf\n", x1);
    printf("x2: %.2lf\n", x2);
    return 0;
}