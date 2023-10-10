#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct node
{
    char data;
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

void push(Stack *stack, char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Pilha Vazia!\n");
        exit(1);
    }
    Node *temp = stack->top;
    stack->top = temp->next;
    free(temp);
}

void print_stack(Stack *stack)
{
    Node *temp = stack->top;
    printf("[ ");
    while (temp)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Stack stack;
    init(&stack);
    char data[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int screen = 0;
    int alive = 1;
    push(&stack, data[screen]);
    while (alive)
    {
        print_stack(&stack);
        printf("Escola as opções de Navegação\n");
        printf("Tela Atual: %c\n", data[screen]);
        printf("1 - Avançar\n");
        printf("2 - Voltar\n");
        printf("3 - Sair\n");
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            screen++;
            push(&stack, data[screen]);
            break;
        case 2:
            pop(&stack);
            screen--;
            break;
        case 3:
            alive = 0;
            break;
        }
    }

    return 0;
}