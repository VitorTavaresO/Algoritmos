#include <stdio.h>

void addProduct(float *money, int amoutProducts, int amout[amoutProducts], float price[amoutProducts], int product, int amoutProduct) {
    if (amoutProduct > 0) {
        amout[product - 1] += amoutProduct;
        *money -= amoutProduct * price[product - 1];
    } else {
        printf("Quantidade invalida\n");
    }

}

void retireProduct(float *money, int amoutProducts, int amout[amoutProducts], float price[amoutProducts], int product, int amoutProduct) {
    if (amoutProduct > 0) {
        amout[product - 1] -= amoutProduct;
        *money += amoutProduct * price[product - 1];
    } else {
        printf("Quantidade invalida\n");
    }

}

int main() {
    float money = 1000.0;
    int amoutProducts = 4;
    int amout[4] = {10, 15, 20, 5};
    float price[4] = {5.0, 4.0, 2.0, 3.0};
    int option;
    while (option != 0) {
        printf("Saldo: %.2f\n", money);
        printf("Escolha uma opcao:\n");
        printf("1 - Adcionar ao estoque\n");
        printf("2 - Retirar do estoque\n");
        scanf("%d", &option);
        if (option == 1) {
            int product, amoutProduct;
                printf("Escolha o produto desejado:\n");
                printf("(1) - Arroz\n");
                printf("Quantidade: %d\n", amout[0]);
                printf("Preco: %.2f\n", price[0]);
                printf("(2) - Feijao\n");
                printf("Quantidade: %d\n", amout[1]);
                printf("Preco: %.2f\n", price[1]);
                printf("(3) - Biscoito\n");
                printf("Quantidade: %d\n", amout[2]);
                printf("Preco: %.2f\n", price[2]);
                printf("(4) - Molho de tomate\n");
                printf("Quantidade: %d\n", amout[3]);
                printf("Preco: %.2f\n", price[3]);
                scanf("%d", &product);
                printf("Digite a quantidade: ");
                scanf("%d", &amoutProduct);
                addProduct(&money, amoutProducts, amout, price, product, amoutProduct);
        } else if (option == 2) {
            int product, amoutProduct;
            printf("Escolha o produto desejado:\n");
                printf("(1) - Arroz\n");
                printf("Quantidade: %d\n", amout[0]);
                printf("Preco: %.2f\n", price[0]);
                printf("(2) - Feijao\n");
                printf("Quantidade: %d\n", amout[1]);
                printf("Preco: %.2f\n", price[1]);
                printf("(3) - Biscoito\n");
                printf("Quantidade: %d\n", amout[2]);
                printf("Preco: %.2f\n", price[2]);
                printf("(4) - Molho de tomate\n");
                printf("Quantidade: %d\n", amout[3]);
                printf("Preco: %.2f\n", price[3]);
            scanf("%d", &product);
            printf("Digite a quantidade: ");
            scanf("%d", &amoutProduct);
            retireProduct(&money, amoutProducts, amout, price, product, amoutProduct);
        }
    }

    return 0;
}