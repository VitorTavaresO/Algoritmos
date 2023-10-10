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
    int min;
    int max;
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
    if (data < stack->min)
        stack->min = data;
    if (data > stack->max)
        stack->max = data;
}

void find_min(Stack *stack)
{
    if (is_empty(stack))
    {
        return;
    }
    Node *temp = stack->top;
    stack->min = temp->data;

    while (temp)
    {
        if (temp->data < stack->min)
        {
            stack->min = temp->data;
        }
        temp = temp->next;
    }
}

void find_max(Stack *stack)
{
    if (is_empty(stack))
    {
        return;
    }
    Node *temp = stack->top;
    stack->max = temp->data;

    while (temp)
    {
        if (temp->data > stack->max)
        {
            stack->max = temp->data;
        }
        temp = temp->next;
    }
}

void pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Pilha Vazia.\n");
        exit(1);
    }
    Node *temp = stack->top;
    stack->top = stack->top->next;

    if (temp->data == stack->min)
        find_min(stack);
    if (temp->data == stack->max)
        find_max(stack);

    free(temp);
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

    return stack->min;
}

int get_max(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Pilha Vazia.\n");
        exit(1);
    }

    return stack->max;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

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