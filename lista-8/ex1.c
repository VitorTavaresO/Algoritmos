#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Automovel{
    char fabricante[20];
    char modelo[20];
    int ano;
    char placa[8];
    char cor[20];
    char combustivel;
    float preco;
    float valorIPVA;
};

int main(){
    struct Automovel carro = {"Ford", "Ka", 2010, "ABC-1234", "Vermelho", 'G', 25000, 0};
        printf("Fabricante: %s \n", carro.fabricante);
        printf("Modelo: %s \n", carro.modelo);
        printf("Ano: %d \n", carro.ano);
        printf("Placa: %s \n", carro.placa);
        printf("Cor: %s \n", carro.cor);
        printf("Combustivel: %c \n", carro.combustivel);
        printf("Preco: %f \n", carro.preco);
        printf("Valor do IPVA: %f \n", carro.valorIPVA);
    return 0;
}