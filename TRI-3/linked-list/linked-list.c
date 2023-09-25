#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        printf("Node not created.\n");
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertHead(Node **list, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *list;
    *list = newNode;
}

void insertMidByPosition(Node **list, int data, int pos)
{
    Node *newNode = createNode(data);
    if (*list == NULL)
    {
        *list = newNode;
        return;
    }
    else
    {
        Node *temp = *list;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertMidByValue(Node **list, int data, int value)
{
    Node *newNode = createNode(data);
    if (*list == NULL)
    {
        *list = newNode;
        return;
    }
    else
    {
        Node *temp = *list;
        while (temp->next && temp->data != value)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertTail(Node **list, int data)
{
    Node *newNode = createNode(data);
    if (*list == NULL)
    {
        *list = newNode;
        return;
    }
    Node *temp = *list;
    while (temp->next)
        temp = temp->next;
    newNode->next = NULL;
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
    printf("]\n");
}

int main()
{
    Node *list = NULL;
    printList(list);

    insertHead(&list, 1);
    printList(list);

    insertHead(&list, 1);
    printList(list);

    insertHead(&list, 1);
    printList(list);

    insertTail(&list, 3);
    printList(list);

    insertTail(&list, 3);
    printList(list);

    insertTail(&list, 3);
    printList(list);

    insertMidByPosition(&list, 2, 2);
    printList(list);

    insertMidByPosition(&list, 2, 6);
    printList(list);

    insertMidByValue(&list, 4, 3);
    printList(list);
}