#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int number;
    struct Node *next;
}
Node;

typedef struct List
{
    Node *root;
}
List;

Node* initNode(int number);
Node* findNode(List *list, int number);
void append(List *list, int number);
void insertAfter(Node *node, int number);
void deleteNode(List *list, int number);
void printList(List *list);
void freeList(List *list);

int main(void)
{
    List *list = malloc(sizeof(List));
    if (list == NULL)
    {
        return 1;
    }
    list->root = initNode(5);
    
    insertAfter(list->root, 4);
    append(list, 3);
    append(list, 2);
    append(list, 1);

    printList(list);

    deleteNode(list, 5);
    printList(list);

    deleteNode(list, 2);
    printList(list);

    freeList(list);
}

Node* findNode(List *list, int number)
{
    Node *tmp = list->root;

    while (tmp != NULL && tmp->number != number)
    {
        tmp = tmp->next;
    }

    return tmp;
}

Node* initNode(int number)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Insufficient memory available\n");
        exit(1);
    }

    node->number = number;
    node->next = NULL;

    return node;
}

void append(List *list, int number)
{
    if (list == NULL)
    {
        printf("List is not allowed to be NULL");
        return;  
    }

    Node *last = list->root;

    while(last->next != NULL)
    {
        last = last->next;
    }

    last->next = initNode(number);

    return;
}

void insertAfter(Node *prev, int number)
{
    if (prev == NULL)
    {
        printf("Previous node is not allowed to be NULL");
        return;
    }

    Node *node = initNode(number);

    if (prev->next != NULL)
    {
        node->next = prev->next;
    }

    prev->next = node;
}

void deleteNode(List *list, int number)
{
    Node *prev = NULL;
    Node *tmp = list->root;

    while(tmp != NULL && tmp->number != number)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    if (prev == NULL)
    {
        list->root = tmp->next;
    }
    else
    {
        prev->next = tmp->next;
    }

    free(tmp);

    return;
}

void printList(List *list)
{
    Node *tmp = list->root;

    while (tmp != NULL)
    {
        printf("%i\n", tmp->number);
        tmp = tmp->next;
    }
}

void freeNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    freeNode(node->next);
    free(node);

    return;
}

void freeList(List *list)
{
    if (list == NULL)
    {
        return;
    }

    freeNode(list->root);
    free(list);
}