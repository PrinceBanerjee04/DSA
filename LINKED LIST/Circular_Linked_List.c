#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// Creation of Circular Linked List
node *create(int n)
{
    node *p, *q, *r;
    int i;
    printf("\nEnter the values : \n");
    p = (node *)malloc(sizeof(node));
    scanf("%d", &(p->data));
    p->next = p; // Circular connection to itself
    q = p;
    for (i = 0; i < n - 1; i++)
    {
        r = (node *)malloc(sizeof(node));
        scanf("%d", &(r->data));
        r->next = p; // Circular connection
        q->next = r;
        q = r;
    }
    return p;
}

// Printing the Circular Linked List
void traverse(node *p)
{
    node *t;
    t = p;
    printf("Circular Linked List: \n");
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != t);
    printf("%d \n", t->data); // back to start
}

// Insertion of an element
void insertlist(node **p, int i, node *t)
{
    int j;
    node *q, *x;
    if (i == 0)
    {
        t->next = *p;
        *p = t;
    }
    q = *p;
    for (j = 1; (j <= i) && (q->next != *p); j++)
    {
        x = q;
        q = q->next;
    }
    t->next = x->next;
    x->next = t;
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
        *p = (*p)->next;
        free(y);
    }
    x = y->next;
    for (j = 1; (j < i) && (x->next != *p); j++)
    {
        y = x;
        x = x->next;
    }
    y->next = x->next;
    x->next = NULL;
    free(x);
}

// Reversing a Circular Linked List
node *reverselist(node *p)
{
    node *l, *q, *n;
    q = p;
    l = NULL;
    do
    {
        n = q->next;
        q->next = l;
        l = q;
        q = n;
    } while (q != p);
    p->next = l;
    return l;
}

// Main Function
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
