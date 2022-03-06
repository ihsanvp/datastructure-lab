#include <stdio.h>

int queue[100];
int size;
int front = 0, rear = -1;

void enqueue();
void dequeue();
void display();

void main()
{
    int choice;

    printf("Enter size of Queue :");
    scanf("%d", &size);

    printf("QUEUE IMPLEMENTATION USING ARRAY\n");
    printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");

    do
    {
        printf("Enter choice [1/2/3/4] :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            break;

        default:
            printf("Please enter valid choice\n");
        }

    } while (choice != 4);
}

void enqueue()
{
    int item;

    if (rear > front && (rear - front) == size - 1)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("Enter data :");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
    }
}

void dequeue()
{
    if (rear < front)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        front++;
    }
}

void display()
{
    int i;

    if (rear < front)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("QUEUE :");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}