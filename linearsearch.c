#include <stdio.h>

void main()
{
    int n, x, pos = -1;

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

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            pos = i;
            break;
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
