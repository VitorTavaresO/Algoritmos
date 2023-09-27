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
void remove_value(Node **list, int value)
{
    if (*list != NULL)
    {
        Node *temp = *list;
        if (temp->data == value)
        {
            *list = temp->next;
            free(temp);
        }
        else
        {
            while (temp->next && (temp->next)->data != value)
            {
                temp = temp->next;
            }
            if (temp->next)
            {
                Node *remove = temp->next;
                temp->next = remove->next;
                free(remove);
            }
        }
    }
}
void remove_position(Node **list, int pos)
{
    if (*list == NULL)
        return;
    Node *temp = *list;
    if (pos == 1)
    {
        *list = temp->next;
        free(temp);
        return;
    }
    for (int i = 2; i < pos; i++)
        temp = temp->next;
    Node *temp2 = temp->next;
    temp->next = temp2->next;
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
            printf("value encontrado\n");
            return;
        }
        temp = temp->next;
    }
    printf("value não encontrado");
}

void ordenate_list(Node **list, int count, int order)
{
    Node *temp = *list;
    int aux;
    if (order == 0)
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (temp->data > (temp->next)->data)
                {
                    aux = temp->data;
                    temp->data = (temp->next)->data;
                    (temp->next)->data = aux;
                }
                temp = temp->next;
            }
            temp = *list;
        }
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (temp->data < (temp->next)->data)
                {
                    aux = temp->data;
                    temp->data = (temp->next)->data;
                    (temp->next)->data = aux;
                }
                temp = temp->next;
            }
            temp = *list;
        }
    }
}

void remove_equal_itens(Node **list)
{
    Node *temp = *list;

    while (temp)
    {
        Node *temp2 = temp->next;

        while (temp2)
        {
            if (temp->data == temp2->data)
            {
                remove_value(list, temp->data);
            }
            temp2 = temp2->next;
        }

        temp = temp->next;
    }
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
        printf("3. Inserir Meio por Posição\n");
        printf("4. Inserir Cauda\n");
        printf("5. Remover por Posição\n");
        printf("6. Remover por Valor\n");
        printf("7. Quantidade de elementos na lista\n");
        printf("8. Limpar lista\n");
        printf("9. Maior elemento da lista\n");
        printf("10. Média dos valores da Lista\n");
        printf("11. Valor existente na lista\n");
        printf("12. Ordenar Lista\n");
        printf("13. Remover Itens Iguais\n");
        printf("17. Sair\n");
        printf("-----------------------");
        printf("Escolha uma opção: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Digite o value a ser inserido: ");
            int value;
            scanf("%d", &value);
            insert_head(value, &list);
            break;
        case 2:
            printf("Digite o value a ser inserido: ");
            scanf("%d", &value);
            printf("Digite a posição a ser inserido: ");
            int pos;
            scanf("%d", &pos);
            insert_mid_position(value, &list, pos);
            break;
        case 3:
            printf("Digite o value a ser inserido: ");
            scanf("%d", &value);
            printf("Digite o value a ser procurado: ");
            int search;
            scanf("%d", &search);
            insert_mid_value(value, &list, search);
            break;
        case 4:
            printf("Digite o value a ser inserido: ");
            scanf("%d", &value);
            insert_tail(value, &list);
            break;
        case 5:
            printf("Digite a posição a ser removida: ");
            scanf("%d", &pos);
            remove_position(&list, pos);
            break;
        case 6:
            printf("Digite o value a ser removida: ");
            scanf("%d", &value);
            remove_value(&list, value);
            break;
        case 7:
            printf("Quantidade de elementos: %d \n", count_itens(&list));
            break;
        case 8:
            clear_list(&list);
            break;
        case 9:
            greather_item(&list);
            break;
        case 10:
            average(&list, count_itens(&list));
            break;
        case 11:
            printf("Digite o value a ser procurado: ");
            scanf("%d", &value);
            find_item(&list, value, count_itens(&list));
            break;
        case 12:
            printf("Digite o tipo de ordenação (crescente(0) ou decrescente(1)): ");
            int order;
            scanf("%d", &order);
            ordenate_list(&list, count_itens(&list), order);
            break;
        case 13:
            remove_equal_itens(&list);
            break;
        case 17:
            alive = 0;
            break;
        }
        print_list(list);
    }
    return 0;
}