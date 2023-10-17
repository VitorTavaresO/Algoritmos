#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct list
{
    Node *top;
} List;

void init(List *list)
{
    list->top = NULL;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Nó não criado");
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void print_list(List *list)
{
    Node *temp = list->top;
    printf("[ ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void insert_head(List *list, int data)
{
    Node *newNode = createNode(data);
    newNode->next = list->top;
    list->top = newNode;
}

void insert_mid(List *list, int data, int value)
{
    if (list->top == NULL)
    {
        printf("Lista Vazia, Valor inserido no começo!\n");
        insert_head(list, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = list->top;
    while (temp->next && (temp->data != value))
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void insert_tail(List *list, int data)
{
    if (list->top == NULL)
    {
        printf("Lista Vazia, Valor inserido no começo!\n");
        insert_head(list, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = list->top;
    while (temp->next)
        temp = temp->next;

    newNode->next = NULL;
    temp->next = newNode;
}

void random_list(List *list)
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        insert_head(list, rand() % 50);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    List list;
    init(&list);
    int alive = 1;
    while (alive)
    {
        print_list(&list);
        printf("--------------------------\n");
        printf("0 - Random List\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no meio por valor\n");
        printf("3 - Inserir no fim\n");
        printf("4 - Remover do início\n");
        printf("5 - Remover do meio por valor\n");
        printf("6 - Remover do fim\n");
        int op;
        int data;
        int value;
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            random_list(&list);
            break;
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &data);
            insert_head(&list, data);
            break;
        case 2:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &data);
            printf("Digite o valor de referencia: ");
            scanf("%d", &value);
            insert_mid(&list, data, value);
            break;
        case 3:
            printf("Digite o valor: ");
            scanf("%d", &data);
            insert_tail(&list, data);
            break;
        case 4:
            // remove_head(&list);
            break;
        case 5:
            printf("Digite o valor: ");
            scanf("%d", &data);
            // remove_middle(&list, data);
            break;
        case 6:
            // remove_tail(&list);
            break;
        }
    }
}