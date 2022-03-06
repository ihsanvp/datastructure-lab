#include <stdio.h>

void bubblesort(int[], int);

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

    bubblesort(a, n);

    printf("Sorted aay :");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubblesort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}