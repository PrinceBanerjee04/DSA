#include <stdio.h>
#include <stdlib.h>

#define size 100

typedef struct queue
{
    int arr[size];
    int front, rear;
} queue;
