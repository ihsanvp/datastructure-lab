#include <stdio.h>

int binarysearch(int[], int, int, int);
int mid;

void main()
{
    int n, x;

    printf("Enter Array length :");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers :", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to search :");
    scanf("%d", &x);

    int mid, pos = -1, low = 0, high = n;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            pos = mid;
            break;
        }

        if (x > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (pos == -1)
    {
        printf("Number '%d' not found in Array\n", x);
    }
    else
    {
        printf("Number '%d' found at position '%d'\n", x, pos);
    }
}

int binarysearch(int arr[], int low, int high, int x)
{
    if (high > low)
    {
        mid = (low + high) / 2;

        if (x == arr[mid])
        {
            return mid;
        }

        if (x > mid)
        {
            return binarysearch(arr, mid + 1, high, x);
        }
        else
        {
            return binarysearch(arr, low, mid - 1, x);
        }
    }
    else
    {
        return -1;
    }
}