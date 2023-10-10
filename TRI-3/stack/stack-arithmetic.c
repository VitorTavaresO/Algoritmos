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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    printf("Informe a expressão desejada(Sem espaços):");
    char expression[70];
    scanf("%s", expression);
    for (int i = 0; i < 70; i++)
    {
        if (expression[i] == '\0')
        {
            break;
        }
        printf("%c", expression[i]);
    }
    Stack stack;
    init(&stack);
    int i = 0;
    int alive = 1;
    while (alive)
    {
        if (expression[i] == '(')
        {
            push(&stack, expression[i]);
        }
        else if (expression[i] == ')')
        {
            pop(&stack);
        }
        else if (expression[i] == '\0')
            alive = 0;

        i++;
    }
    if (is_empty(&stack))
        printf("Expressão Válida!");
    else
        printf("Expressão Inválida");

    return 0;
}