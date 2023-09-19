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

void insertMid(Node **list, int data, int pos)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node *temp = *list;
    for (int i = 0; i < pos; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
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
    int position = 0;
    printf("[");
    while (list)
    {
        printf(" %d", list->data);
        list = list->next;
    }
    printf("]");
}

int main()
{
    Node *list = NULL;
    insertHead(&list, 1);
    insertHead(&list, 1);
    insertHead(&list, 1);
    insertTail(&list, 3);
    insertTail(&list, 3);
    insertTail(&list, 3);
    insertMid(&list, 2, 2);
    insertMid(&list, 2, 6);
    printList(list);
}