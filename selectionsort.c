#include <stdio.h>

void selectionsort(int[], int);

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

    selectionsort(a, n);

    printf("Sorted Array :");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selectionsort(int a[], int n)
{
    int i, j, temp, min;

    for (i = 0; i < n; i++)
    {
        min = i;

        for (j = i; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}