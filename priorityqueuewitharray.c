#include <stdio.h>

int queue[100];
int size;
int front = -1, rear = -1;

void insert_by_priority();
void delete_by_priority();
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
            insert_by_priority();
            break;

        case 2:
            delete_by_priority();
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

void insert_by_priority()
{
    int item, i, j;

    if (rear > front && (rear - front) == size - 1)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("Enter value to insert :");
        scanf("%d", &item);

        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            queue[rear] = item;
        }
        else
        {
            for (i = 0; i <= rear; i++)
            {
                if (item >= queue[i])
                {
                    for (j = rear + 1; j > i; j--)
                    {
                        queue[j] = queue[j - 1];
                    }
                    break;
                }
            }
            queue[i] = item;
            rear++;
        }
    }
}

void delete_by_priority()
{
    int item, i, j;

    if (rear == -1 && front == -1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("Enter item to delete :");
        scanf("%d", &item);

        for (i = 0; i <= rear; i++)
        {
            if (item == queue[i])
            {
                for (j = i; j < rear; j++)
                {
                    queue[j] = queue[j + 1];
                }
                rear--;

                if (rear == -1)
                {
                    front = -1;
                }

                return;
            }
        }

        printf("'%d' not found in Queue\n", item);
    }
}

void display()
{
    int i;

    if (rear == -1 && front == -1)
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