#include <stdio.h>
#include <stdlib.h>

#define size 100

typedef struct queue
{
    int arr[size];
    int front, rear;
} queue;

int addcirq(int a, queue *q)
{
    if ((q->rear + 1) % size == q->front)
        return 0; // Queue is full
    else
    {
        if (q->front == -1) // If queue is initially empty
            q->front = 0;
        q->rear = (q->rear + 1) % size;
        q->arr[q->rear] = a;
        return 1; // Element added successfully
    }
}

int deletecirq(queue *q)
{
    if (q->rear == q->front)
    {
        // Queue is empty, reset front and rear
        q->front = -1;
        q->rear = -1;
        return 0;
    }
    else
    {
        q->front = (q->front + 1) % size;
        return 1; // Element deleted successfully
    }
}

void display(queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is Empty. Nothing to Display\n");
        return;
    }
    int i = q->front;
    do
    {
        printf("%d\n", q->arr[i]);
        i = (i + 1) % size;
    } while (i != (q->rear + 1) % size && i != q->front);
    printf("\n");
}
