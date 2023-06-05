#include <stdio.h>

void ler_matrix(int matrix[100][100], int *linhas, int *colunas) {
    int linha = 1;
    int coluna = 0;
    int numero;
    
    while (1) {
        scanf("%d", &numero);
        
        if (numero == -1) {
            linha++;
            coluna = 0;
        } else if (numero >= 0) {
            matrix[linha][coluna] = numero;
            coluna++;
            
            if (coluna == *colunas) {
                linha++;
                coluna = 0;
            }
        } else if (numero == -2) {
            break;
        }
    }
    
    *linhas = linha;
    *colunas = coluna;
}

int main() {

    int matrix[100][100] = {{0}};
    
    int linhas = 100;
    int colunas = 100;

    printf("Digite os numeros da matriz (use -1 para indicar o fim da linha e -2 para indicar o fim da matrix):\n");
    ler_matrix(matrix, &linhas, &colunas);

    printf("Colunas: %d\n", colunas);
    printf("Linhas: %d\n", linhas);

    return 0;
}