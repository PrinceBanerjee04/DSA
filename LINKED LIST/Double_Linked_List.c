#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

// Creation of the List
node *create(int n)
{
    node *p, *q, *r;
    int i;
    printf("\nEnter the values:\n");
    p = (node *)malloc(sizeof(node));
    scanf("%d", &(p->data));
    p->next = NULL;
    p->prev = NULL;
    q = p;
    for (i = 0; i < n - 1; i++)
    {
        r = (node *)malloc(sizeof(node));
        scanf("%d", &(r->data));
        r->next = NULL;
        r->prev = q;
        q->next = r;
        q = r;
    }
    return p;
}

// Printing the Linked List
void traverse(node *p)
{
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// Insertion of an element
void insertlist(node **p, int i, node *t)
{
    int j;
    node *q, *x;
    if (i == 0)
    {
        t->next = *p;
        t->prev = NULL;
        if (*p != NULL)
        {
            (*p)->prev = t;
        }
        *p = t;
        return;
    }
    q = *p;
    for (j = 1; (j <= i) && (q != NULL); j++)
    {
        x = q;
        q = q->next;
    }
    t->prev = x;
    t->next = x->next;
    x->next = t;
    x->next->prev = t;
    return;
}

// Deletion of an element
void deletelist(node **p, int i)
{
    int j;
    node *y, *x;
    y = *p;
    if (i == 0)
    {
        if (y != NULL)
        {
            *p = y->next;
            if (*p != NULL)
            {
                (*p)->prev = NULL;
            }
            free(y);
        }
        return;
    }
    x = y->next;
    for (j = 1; (j < i) && (x != NULL); j++)
    {
        y = x;
        x = x->next;
    }
    if (x != NULL)
    {
        y->next = x->next;
        if (x->next != NULL)
        {
            x->next->prev = y;
        }
        free(x);
    }
    return;
}

// Reversing of the list
node *reverselist(node *p)
{
    node *q = p;
    node *temp;
    while (q != NULL)
    {
        temp = q->prev;
        q->prev = q->next;
        q->next = temp;

        p = q;       // Move p to current node
        q = q->prev; // Move q to the next node
    }
    return p;
}

// Main Function
int main()
{
    int n;
    printf("Enter N : ");
    scanf("%d", &n);
    node *p = create(n);
    printf("Traversing of Doubly Linked List:\n");
    traverse(p);
    printf("\nEnter 1 to insert an element,2 to delete an element,3 to reverse the list\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        int pos;
        printf("Enter the position to enter the element : ");
        scanf("%d", &pos);
        node *t = (node *)malloc(sizeof(node));
        int new_data;
        printf("Enter the data to be entered : ");
        scanf("%d", &new_data);
        t->data = new_data;
        insertlist(&p, pos, t);
        printf("\nList after insertion : \n");
        traverse(p);
    }
    break;
    case 2:
    {
        int pos;
        printf("Enter the position to be deleted : ");
        scanf("%d", &pos);
        deletelist(&p, pos);
        printf("\nList after deletion : \n");
        traverse(p);
    }
    break;
    case 3:
    {
        p = reverselist(p);
        printf("\nReversed List : \n");
        traverse(p);
    }
    break;
    default:
        printf("WRONG CHOICE!!!");
    }
    return (0);
}
