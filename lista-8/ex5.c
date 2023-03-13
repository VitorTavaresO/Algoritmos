#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Tecido{
    int codigo;
    char descricao[100];
    float precoMetro;
    float quantidadeEstoque
};

int main(){
    struct Tecido lote1[30] = {
        {1, "Algodao-1", 1.00, 40.00},
        {2, "Linho-1", 0.60, 30.00},
        {3, "Seda-1", 5.00, 60.50},
        {4, "Lã-1", 1.40, 20.00},
        {5, "Algodao-2", 0.50, 10.00},
        {6, "Linho-2", 1.30, 15.50},
        {7, "Seda-2", 2.00, 20.00},
        {8, "Lã-2", 1.00, 30.00},
        {90, "Algodao-3", 1.00, 40.00},
        {10, "Linho-3", 0.60, 30.00},
        {11, "Seda-3", 5.00, 60.50},
        {12, "Lã-3", 1.40, 20.00},
        {13, "Algodao-4", 0.50, 10.00},
        {14, "Linho-4", 1.30, 15.50},
        {15, "Seda-4", 2.00, 20.00},
        {16, "Lã-4", 1.00, 30.00},
        {17, "Algodao-5", 1.00, 40.00},
        {18, "Linho-5", 0.60, 30.00},
        {19, "Seda-5", 5.00, 60.50},
        {20, "Lã-5", 1.40, 20.00},
        {21, "Algodao-6", 0.50, 10.00},
        {22, "Linho-6", 1.30, 15.50},
        {23, "Seda-6", 2.00, 20.00},
        {24, "Lã-6", 1.00, 30.00},
        {25, "Algodao-7", 1.00, 40.00},
        {26, "Linho-7", 0.60, 30.00},
        {27, "Seda-7", 5.00, 60.50},
        {28, "Lã-7", 1.40, 20.00},
        {29, "Algodao-8", 0.50, 10.00},
        {30, "Linho-8", 1.30, 15.50},
    };

    printf("Tecidos do lote 1: \n");
    for (int i = 0; i < 30; i++){
        printf("Codigo: %d \n", lote1[i].codigo);
        printf("Descricao: %s \n", lote1[i].descricao);
        printf("Preco por metro: %2.f \n", lote1[i].precoMetro);
        printf("Quantidade em estoque: %2.f \n", lote1[i].quantidadeEstoque);
        printf("------------------------ \n");
    }

    printf("Tecidos do lote 1 com estoque inferior a 50 metros \n");
    for(int i = 0; i < 30; i++){
        if(lote1[i].quantidadeEstoque < 50.0){
            printf("Codigo: %d \n", lote1[i].codigo);
            printf("Descricao: %s \n", lote1[i].descricao);
            printf("Preco por metro: %2.f \n", lote1[i].precoMetro);
            printf("Quantidade em estoque: %2.f \n", lote1[i].quantidadeEstoque);
            printf("------------------------ \n");
        }
    }

    printf("Tecidos do lote 1 com preco inferior a R$0,60 o metro \n");
    for(int i = 0; i < 30; i++){
        if(lote1[i].precoMetro < 0.60){
            printf("Codigo: %d \n", lote1[i].codigo);
            printf("Descricao: %s \n", lote1[i].descricao);
            printf("Preco por metro: %2.f \n", lote1[i].precoMetro);
            printf("Quantidade em estoque: %2.f \n", lote1[i].quantidadeEstoque);
            printf("------------------------ \n");
        }
    }

    return 0;
}