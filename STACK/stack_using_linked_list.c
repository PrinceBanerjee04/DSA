#include <stdio.h>
#include <stdlib.h>

#define size 100

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct stack
{
    struct node *top;
} stack;

int push(int a, stack *s)
{
    node *x;
    x = (node *)malloc(sizeof(node));
    x->data = a;
    x->next = s->top;
    s->top = x;
}

int pop(stack *s)
{
    if (s->top == NULL)
        return 0;
    s->top = s->top->next;
}

void display(stack *s)
{
    node *a = s->top;
    if (s->top == NULL)
        printf("Stack is Empty.Nothing to Display");
    while (s->top != NULL)
    {
        printf("%d\n", (s->top->data));
        s->top = s->top->next;
    }
    s->top = a;
    printf("\n");
}

int main()
{
    stack s;
    s.top = NULL;
    int choice, element;
    do
    {
        printf("\nStack Operations:\n1. Push 2. Pop 3. Display 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            if (push(element, &s))
                printf("Element %d pushed to stack.\n", element);
            break;
        case 2:
            if (pop(&s))
                printf("Element popped from stack.\n");
            else
                printf("Stack is empty. Cannot pop element.\n");
            break;
        case 3:
            display(&s);
            break;
        case 4:
            printf("Exiting the program.\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
