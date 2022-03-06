#include <stdio.h>

void main()
{
    int n, x, mid, low, high, pos = -1;

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

    low = 0;
    high = n;

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