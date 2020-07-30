#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    int number;
    struct Node *left;
    struct Node *right;
}
Node;

typedef struct Tree
{
    Node *root;
}
Tree;

Node* initNode(int n);
Node* findNode(Node *node, int value);
void insertNodes(Tree *tree, int values[], int size);
void printTree(Tree *tree);
void freeTree(Tree *tree);
int countNodes(Node *node, int value);

int main(void)
{
    Tree *tree = malloc(sizeof(Tree));
    if (tree == NULL)
    {
        return 1;
    }
    tree->root = NULL;

    Node *node = initNode(5);
    if (node == NULL)
    {
        return 1;
    }
    tree->root = node;

    int values[] = { 9, 7, 8, 4, 6, 2, 3, 0, 1 };
    insertNodes(tree, values, sizeof(values) / sizeof(int));

    printTree(tree);
    printf("size: %i\n", countNodes(tree->root, 0));

    freeTree(tree);
}

Node* initNode(int n)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
    {
        return NULL;
    }
    node->number = n;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insertNode(Node *root, int value)
{
    if (root == NULL)
    {
        return initNode(value);
    }

    if (root->number < value)
    {
        root->right = insertNode(root->right, value);
    }
    if (root->number > value)
    {
        root->left = insertNode(root->left, value);
    }

    return root;
}
void insertNodes(Tree *tree, int values[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insertNode(tree->root, values[i]);
    }
}

Node* findNode(Node *node, int value)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (node->number == value)
    {
        return node;
    }

    if (node->number < value)
    {
        return findNode(node->right, value);
    }
    if (node->number > value)
    {
        return findNode(node->left, value);
    }

    return NULL;
}

int countNodes(Node *node, int value)
{
    if (node == NULL)
    {
        return value;
    }

    value = countNodes(node->right, value);
    value = countNodes(node->left, value);

    return ++value;
}

void printNode(Node *node)
{
    if (node->left != NULL)
    {
        printNode(node->left);
    }

    printf("%i\n", node->number);

    if (node->right != NULL)
    {
        printNode(node->right);
    }
}

void printTree(Tree *tree)
{
    printNode(tree->root);
}

void freeNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    freeNode(node->right);
    freeNode(node->left);
    free(node->number);
    free(node);
}

void freeTree(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }

    freeNode(tree->root);
    free(tree);
}