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
    Node *head;
} List;

int init(List *list)
{
    list->head = NULL;
}

void insert_head(int data, List *list)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void random_list(List *list)
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        insert_head(rand() % 100, list);
    }
}

void print_list(List *list)
{
    Node *temp = list->head;
    printf("[");
    while (list)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

int main()
{
    List list;
    init(&list);
    random_list(&list);
    print_list(&list);
}