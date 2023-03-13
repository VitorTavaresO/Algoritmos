#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Imovel{
    int numeroCadastro;
    float valorImposto;
    int mesesAtraso;
};

int main(){
    struct Imovel imovel[3] = {
        {1, 1000, 0},
        {2, 2000, 2},
        {3, 1500, 6},
    };
    
    for (int i = 0; i < 3; i++){
        printf("Numero de cadastro: %d \n", imovel[i].numeroCadastro);
        printf("Valor do imposto: %2.f \n", imovel[i].valorImposto);
        printf("Meses de atraso: %d \n", imovel[i].mesesAtraso);
        printf("Multa: %2.f \n", imovel[i].mesesAtraso * 10.0);
        printf("------------------------ \n");
    }

    return 0;
}