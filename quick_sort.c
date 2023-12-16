#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int lower, int upper)
{
    int i, p, q, t;
    i = a[lower];
    p = lower + 1;
    q = upper;
    while (q >= p)
    {
        while (a[p] < i)
            p++;
        while (a[q] > i)
            q--;
        if (q > p)
        {
            t = a[p];
            a[p] = a[q];
            a[q] = t;
        }
    }
    t = a[lower];
    a[lower] = a[q];
    a[q] = t;
    return q;
}

void quicksort(int a[], int lower, int upper)
{
    int i;
    if (upper > lower)
    {
        i = partition(a, lower, upper);
        quicksort(a, lower, i - 1);
        quicksort(a, i + 1, upper);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
