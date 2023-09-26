#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *create_node(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        printf("Node not created.\n");
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_head(int data, Node **list)
{
    Node *newNode = create_node(data);
    newNode->next = *list;
    *list = newNode;
}

void insert_mid_position(int data, Node **list, int pos)
{
    Node *newNode = create_node(data);
    if (*list == NULL)
    {
        *list = newNode;
        return;
    }
    Node *temp = *list;
    for (int i = 1; i < pos; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insert_mid_value(int data, Node **list, int value)
{
    Node *newNode = create_node(data);
    if (*list == NULL)
    {
        *list = newNode;
        return;
    }
    Node *temp = *list;
    while (temp->next && temp->data != value)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insert_tail(int data, Node **list)
{
    Node *newNode = create_node(data);
    if (*list == NULL)
    {
        *list = newNode;
        return;
    }
    Node *temp = *list;
    while (temp->next)
        temp = temp->next;
    newNode->next = NULL;
    temp->next = newNode;
}

void remove_head(Node **list)
{
    if (*list == NULL)
        return;
    Node *temp = *list;
    *list = temp->next;
    free(temp);
}

void remove_mid_position(Node **list, int pos)
{
    if (*list == NULL)
        return;
    Node *temp = *list;
    for (int i = 1; i < pos; i++)
        temp = temp->next;
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void remove_mid_value(Node **list, int value)
{
    if (*list == NULL)
        return;
    Node *temp = *list;
    while (temp->next && temp->data != value)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void remove_tail(Node **list)
{
    if (*list == NULL)
        return;
    Node *temp = *list;
    while ((temp->next)->next)
        temp = temp->next;
    Node *temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
}

int count_itens(Node **list)
{
    int count;
    Node *temp = *list;
    while (temp->next)
    {
        temp = temp->next;
        count++;
    }
    return count + 1;
}

void clear_list(Node **list)
{
    Node *temp = *list;
    while (temp->next)
    {
        Node *temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    *list = NULL;
}

void greather_item(Node **list)
{
    Node *temp = *list;
    int greather = temp->data;
    do
    {
        temp = temp->next;
        if (temp->data > greather)
            greather = temp->data;
    } while (temp->next);
    printf("Maior Elemento: %d \n", greather);
}

void average(Node **list, int count)
{
    Node *temp = *list;
    int sum = temp->data;
    do
    {
        temp = temp->next;
        sum += temp->data;
    } while (temp->next);

    printf("Média dos Elementos: %d \n", (sum / count));
}

void find_item(Node **list, int value, int count)
{
    Node *temp = *list;
    for (int i = 0; i < count; i++)
    {
        if (temp->data == value)
        {
            printf("Valor encontrado\n");
            return;
        }
        temp = temp->next;
    }
    printf("Valor não encontrado");
}

void print_list(Node *list)
{
    printf("[");
    while (list)
    {
        printf(" %d", list->data);
        list = list->next;
    }
    printf("]\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int alive = 1;
    Node *list = NULL;
    while (alive)
    {
        int option;
        printf("----------------------- \n");
        printf("1. Inserir Cabeça\n");
        printf("2. Inserir Meio por Posição\n");
        printf("3. Inserir Meio por Valor\n");
        printf("4. Inserir Cauda\n");
        printf("5. Remover Cabeça\n");
        printf("6. Remover Meio por Posição\n");
        printf("7. Remover Meio por Valor\n");
        printf("8. Remover Cauda\n");
        printf("9. Quantidade de elementos na lista\n");
        printf("10. Limpar lista\n");
        printf("11. Maior elemento da lista\n");
        printf("12. Média dos valores da Lista\n");
        printf("13. Valor existente na lista\n");
        printf("17. Sair\n");
        printf("-----------------------");
        printf("Escolha uma opção: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            int value;
            scanf("%d", &value);
            insert_head(value, &list);
            break;
        case 2:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &value);
            printf("Digite a posição a ser inserido: ");
            int pos;
            scanf("%d", &pos);
            insert_mid_position(value, &list, pos);
            break;
        case 3:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &value);
            printf("Digite o valor a ser procurado: ");
            int search;
            scanf("%d", &search);
            insert_mid_value(value, &list, search);
            break;
        case 4:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &value);
            insert_tail(value, &list);
            break;
        case 5:
            remove_head(&list);
            break;
        case 6:
            printf("Digite a posição a ser removida: ");
            scanf("%d", &pos);
            remove_mid_position(&list, pos);
            break;
        case 7:
            printf("Digite o valor a ser removida: ");
            scanf("%d", &value);
            remove_mid_position(&list, value);
            break;
        case 8:
            remove_tail(&list);
            break;
        case 9:
            printf("Quantidade de elementos: %d \n", count_itens(&list));
            break;
        case 10:
            clear_list(&list);
            break;
        case 11:
            greather_item(&list);
            break;
        case 12:
            average(&list, count_itens(&list));
            break;
        case 13:
            printf("Digite o valor a ser procurado: ");
            scanf("%d", &value);
            find_item(&list, value, count_itens(&list));
            break;
        case 17:
            alive = 0;
            break;
        }
        print_list(list);
    }
    return 0;
}