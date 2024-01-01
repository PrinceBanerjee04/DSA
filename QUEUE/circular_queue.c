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
