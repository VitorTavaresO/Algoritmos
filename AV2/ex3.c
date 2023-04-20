#include <stdio.h>
struct circulo {
    int raio;
};

int main(void) {
    struct circulo c1;
    float pi = 3.1415, area, circunferencia;
    c1.raio = 10;
    area = pi * (c1.raio * c1.raio);
    circunferencia = 2 * pi * c1.raio;
    printf("Area: %.2f - Circunferencia: %.2f", area, circunferencia);
    return 0;
}