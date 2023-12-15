#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct queue
{
    struct node *front;
    struct node *rear;
} queue;

int addq(int a, queue *q)
{
    node *x = (node *)malloc(sizeof(node));
    if (q->front == NULL)
    {
        q->front = x;
        q->rear = x;
    }
    x->data = a;
    q->rear->next = x;
    x->next = NULL;
    q->rear = x;
}

int deleteq(queue *q)
{
    if (q->front == NULL)
        return 0;
    q->front = q->front->next;
}

void display(queue *q)
{
    node *f = q->front;
    if (q->front == NULL)
        printf("Queue is Empty.Nothing to Display");
    while (q->front != NULL)
    {
        printf("%d \n", q->front->data);
        q->front = q->front->next;
    }
    q->front = f;
    printf("\n");
}

int main()
{
    queue q;
    q.front = NULL;
    q.rear = NULL;
    int choice, element;
    do
    {
        printf("\nQueue Operations:\n1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            if (addq(element, &q))
                printf("Element %d added to queue.\n", element);
            else
                printf("Queue is full. Cannot insert element.\n");
            break;
        case 2:
            if (deleteq(&q))
                printf("Element deleted from queue.\n");
            else
                printf("Queue is Empty. Cannot delete element.\n");
            break;
        case 3:
            display(&q);
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
