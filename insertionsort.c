#include <stdio.h>

void insertionsort(int[], int);

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

    insertionsort(a, n);

    printf("Sorted Array :");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionsort(int a[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (a[j] > key && j > 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}