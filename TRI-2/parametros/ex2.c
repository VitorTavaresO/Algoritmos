#include <stdio.h>
#include <math.h>

void coordinatesToPolar(double x, double y, double *r, double *s){
    double aux = x;
    *r = sqrt((x * x) + (y * y));
    *s = atan(y / aux);
}

int main(){
    while(1){
    double x, y, r, s;
    printf("Digite o valor de x: ");
    scanf("%lf", &x);
    printf("Digite o valor de y: ");
    scanf("%lf", &y);
    coordinatesToPolar(x, y, &r, &s);
    printf("x: %.2lf\n", r);
    printf("y: %.2lf\n", s);
    }
    return 0;
}