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

// Printing the Double Circular Linked List
void traverse(node *p)
{
    node *t;
    t = p;
    printf("Double Circular Linked List: \n");
    do
    {
        printf("%d <-> ", p->data);
        p = p->next;
    } while (p != t);
    printf("%d \n", t->data);
}

// Insertion of an element
void insertlist(node **p, int i, node *t)
{
    int j;
    node *q, *x;
    if (i == 0)
    {
        t->next = *p;
        t->prev = (*p)->prev; // Update previous node of t
        (*p)->prev->next = t; // Update next of previous node of *p
        (*p)->prev = t;        // Update previous of *p
        *p = t;
    }
    else
    {
        q = *p;
        for (j = 1; (j <= i) && (q->next != *p); j++)
        {
            x = q;
            q = q->next;
        }
        t->next = x->next;
        t->prev = x;           // Update previous of t
        x->next->prev = t;     // Update previous of next node after x
        x->next = t;           // Update next of x
    }
}
