#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev; 
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

// Deletion of an element
void deletelist(node **p, int i)
{
    int j;
    node *y, *x;
    y = *p;
    if (i == 0)
    {
        (*p)->prev->next = (*p)->next; // Update next of previous node of *p
        (*p)->next->prev = (*p)->prev; // Update previous of next node after *p
        *p = (*p)->next;
        free(y);
    }
    else
    {
        x = y->next;
        for (j = 1; (j < i) && (x->next != *p); j++)
        {
            y = x;
            x = x->next;
        }
        y->next = x->next;
        x->next->prev = y; // Update previous of next node after x
        free(x);
    }
}

// Reversing a Double Circular Linked List
node *reverselist(node *p)
{
    node *q = p;
    do
    {
        node *temp = q->next;
        q->next = q->prev;
        q->prev = temp;
        q = temp;
    } while (q != p);

    return q->prev; // Return the new head of the reversed list
}

int main()
{
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    node *p = create(n);
    printf("\nThe list is: \n");
    traverse(p);
    printf("\nEnter 1 to insert an element, 2 to delete an element,3 to reverse the list\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        int pos;
        printf("Enter the position to enter the element: ");
        scanf("%d", &pos);
        node *t = (node *)malloc(sizeof(node));
        int new_data;
        printf("Enter the data to be entered: ");
        scanf("%d", &new_data);
        t->data = new_data;
        insertlist(&p, pos, t);
        printf("\nList after insertion: \n");
        traverse(p);
    }
    break;
    case 2:
    {
        int pos;
        printf("Enter the position to be deleted: ");
        scanf("%d", &pos);
        deletelist(&p, pos);
        printf("\nList after deletion: \n");
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
    return 0;
}
