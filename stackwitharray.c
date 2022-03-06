#include <stdio.h>

int stack[100];
int top = -1;
int size;

void push();
void pop();
void peek();
void display();

void main()
{
    int choice;

    printf("Enter size of stack :");
    scanf("%d", &size);

    printf("STACK IMPLEMENTATION USING ARRAY\n");

    do
    {
        printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        printf("Enter choice [1/2/3/4/5] :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            break;

        default:
            printf("Please enter valid choice\n");
        }

    } while (choice != 5);
}

void push()
{
    int item;

    if (top > size - 1)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("Enter data :");
        scanf("%d", &item);
        top++;
        stack[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("UNDEFLOW\n");
    }
    else
    {
        printf("Top element : %d\n", stack[top]);
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("STACK :");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}