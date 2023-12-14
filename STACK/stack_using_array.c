#include <stdio.h>
#include <stdlib.h>

#define size 100

typedef struct stack
{
    int arr[size];
    int top;
} stack;

int push(int a, stack *s)
{
    if (s->top == size)
        return 0;
    else
    {
        s->top += 1;
        s->arr[s->top] = a;
    }
}

int pop(stack *s)
{
    if (s->top == -1)
        return 0;
    else
        s->top -= 1;
    return 1;
}

void display(stack *s)
{
    int a=s->top;
    if (s->top == -1)
        printf("Stack is Empty.Nothing to Display");
    while (s->top != -1)
    {
        printf("%d\n", (s->arr[s->top]));
        s->top -= 1;
    }
    s->top=a;
    printf("\n");
}

int main()
{
    stack s;
    s.top = -1;
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
            else
                printf("Stack is full. Cannot push element.\n");
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
