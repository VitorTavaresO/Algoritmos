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
    struct stack *min;
    struct stack *max;
} Stack;

void init(Stack *stack)
{
    stack->top = NULL;
    stack->min = (Stack *)malloc(sizeof(Stack));
    stack->max = (Stack *)malloc(sizeof(Stack));
    stack->min->top = NULL;
    stack->max->top = NULL;
}

int is_empty(Stack *stack)
{
    return stack->top == NULL;
}

void push_min(Stack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

void push_max(Stack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

void push(Stack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

    if (is_empty(stack->min) || data <= stack->min->top->data)
    {
        push_min(stack->min, data);
    }
    if (is_empty(stack->max) || data >= stack->max->top->data)
    {
        push_max(stack->max, data);
    }
}

void pop_min(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Pilha Vazia.\n");
        exit(1);
    }
    Node *temp = stack->top;
    stack->top = temp->next;
    free(temp);
}

void pop_max(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Pilha Vazia.\n");
        exit(1);
    }
    Node *temp = stack->top;
    stack->top = temp->next;
    free(temp);
}

int pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Pilha Vazia.\n");
        exit(1);
    }
    Node *temp = stack->top;
    stack->top = temp->next;
    free(temp);
    int data = temp->data;
    if (data == stack->min->top->data)
    {
        pop_min(stack->min);
    }
    if (data == stack->max->top->data)
    {
        pop_max(stack->max);
    }
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

int get_min(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Pilha Vazia.\n");
        exit(1);
    }
    Node *temp = stack->top;
    int min = temp->data;
    while (temp)
    {
        if (min > temp->data)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

int get_max(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Pilha Vazia.\n");
        exit(1);
    }
    Node *temp = stack->top;
    int max = temp->data;
    while (temp)
    {
        if (max < temp->data)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
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
        printf("4 - Menor Elemento\n");
        printf("5 - Maior Elemento\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            alive = 0;
            break;
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
            printf("Menor Elemento: %d \n", get_min(&stack));
            break;
        case 5:
            printf("Maior Elemento: %d \n", get_max(&stack));
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    }
    return 0;
}