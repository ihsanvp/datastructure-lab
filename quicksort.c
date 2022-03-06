#include <stdio.h>

void quicksort(int[], int, int);
int partition(int[], int, int);

void main()
{
    int n, i;

    printf("Enter Array length :");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d numbers :", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n);

    printf("Sorted Array :");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int i, j, pivot, temp;

    pivot = a[high];
    i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int j = partition(a, low, high);

        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}