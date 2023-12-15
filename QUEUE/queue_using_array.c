#include <stdio.h>
#include <stdlib.h>

#define size 100

typedef struct queue
{
    int arr[size];
    int front, rear;
} queue;

int addq(int a, queue *q)
{
    if (q->rear == size)
        return 0;
    else
    {
        q->rear += 1;
        q->arr[q->rear] = a;
    }
}

int deleteq(queue *q)
{
    if (q->rear == q->front)
    {
        q->rear = -1;
        q->front = -1;
        return 0;
    }
    else
    {
        q->front+=1;
    }
}

void display(queue *q)
{
    int f=q->front;
    int r=q->rear;
    if (q->rear == q->front)
        printf("Queue is Empty.Nothing to Display");
    while (q->front != q->rear)
    {
        q->front+=1;
        printf("%d\n", (q->arr[q->front]));
    }
    q->front=f;
    q->rear=r;
    printf("\n");
}

int main()
{
    queue q;
    q.front = -1;
    q.rear=-1;
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
                printf("Queue is empty. Cannot delete element.\n");
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
