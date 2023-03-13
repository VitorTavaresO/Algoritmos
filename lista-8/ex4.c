#include <stdio.h>
#include <conio.h>
#include <string.h>

struct PassagemOnibus {
    int codigoLocalPartida;
    int codigoLocalChegada;
    int poltrona;
    char posicaoAssento;
};

int main(){
    struct PassagemOnibus passagem[2] = {
        {1, 2, 1, 'J'},
        {2, 3, 2, 'C'},
    };

    for(int i= 0; i <2; i++){
        printf("Codigo do local de partida: %d \n", passagem[i].codigoLocalPartida);
        printf("Codigo do local de chegada: %d \n", passagem[i].codigoLocalChegada);
        printf("Poltrona: %d \n", passagem[i].poltrona);
        printf("Posicao do assento J(Janela) C(Corredor): %c \n", passagem[i].posicaoAssento);
        printf("------------------------ \n");
    }
}