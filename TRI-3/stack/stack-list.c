#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct stack
{
    Node *top;
} Stack;

void init(Stack *stack)
{
    stack->top = NULL;
}

int is_empty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Pilha Vazia.\n");
        exit(1);
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void print_stack(Stack *stack)
{
    Node *temp = stack->top;
    printf("[ ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Stack stack;
    init(&stack);
    int data;
    int alive = 1;
    while (alive)
    {
        int op;
        printf("1 - Inserir na Pilha\n");
        printf("2 - Remover da Pilha\n");
        printf("3 - Imprimir Pilha\n");
        printf("4 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &data);
            push(&stack, data);
            break;
        case 2:
            pop(&stack);
            break;
        case 3:
            print_stack(&stack);
            break;
        case 4:
            alive = 0;
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    }
    return 0;
}