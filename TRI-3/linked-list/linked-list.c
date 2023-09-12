#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insertHead(Node **list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *list;
    *list = newNode;
}

void insertTail(Node **list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*list == NULL)
    {
        *list = newNode;
        return;
    }
    Node *temp = *list;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node *list)
{
    printf("[");
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("]");
}

int main()
{
    Node *list = NULL;
    insertHead(&list, 1);
    insertHead(&list, 2);
    insertHead(&list, 3);
    insertHead(&list, 4);
    insertHead(&list, 5);
    insertTail(&list, 6);
    insertTail(&list, 7);
    insertTail(&list, 8);
    insertTail(&list, 9);
    printList(list);
}