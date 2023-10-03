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
    stack->top = (stack->top)->next;
    free(temp);
    return data;
}

void print_stack(Stack *stack)
{
    Node *temp = stack->top;
    printf("[");
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

    for (int i = 0; i < 10; i++)
        push(&stack, rand() % 100);

    int data = pop(&stack);
    print_stack(&stack);
    printf("Data: %d\n", data);
    print_stack(&stack);

    return 0;
}