#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev; // New pointer to previous node
} node;

// Creation of Double Circular Linked List
node *create(int n)
{
    node *p, *q, *r;
    int i;
    printf("\nEnter the values : \n");
    p = (node *)malloc(sizeof(node));
    scanf("%d", &(p->data));
    p->next = p; // Circular connection to itself
    p->prev = p; // Circular connection to itself for previous node
    q = p;
    for (i = 0; i < n - 1; i++)
    {
        r = (node *)malloc(sizeof(node));
        scanf("%d", &(r->data));
        r->next = p; // Circular connection
        r->prev = q; // Set previous node
        q->next = r;
        p->prev = r; // Set previous node of first node
        q = r;
    }
    return p;
}
