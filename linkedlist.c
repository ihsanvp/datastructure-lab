#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} node;

node *head = NULL;
node *temp = NULL;
node *new = NULL;
node *ptr = NULL;

void insert_front();
void insert_end();
void insert_any();
void delete_front();
void delete_end();
void delete_any();
void display();

void main()
{
    int choice;

    printf("LINKED LIST OPERATIONS\n");
    printf("1.INSERT AT FRONT\n2.INSERT AT END\n3.INSERT AT POSITION\n4.DELETE FROM FRONT\n5.DELETE FROM END\n6.DELETE FROM POSITION\n7.DISPLAY\n8.EXIT\n");

    do
    {
        printf("Enter choice [1/2/3/4/5/6/7/8] :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_front();
            break;

        case 2:
            insert_end();
            break;

        case 3:
            insert_any();
            break;

        case 4:
            delete_front();
            break;

        case 5:
            delete_end();
            break;

        case 6:
            delete_any();
            break;

        case 7:
            display();
            break;

        case 8:
            break;

        default:
            printf("Please enter valid choice\n");
        }

    } while (choice != 8);
}

void insert_front()
{
    int item;

    printf("Enter data :");
    scanf("%d", &item);

    new = (node *)malloc(sizeof(node));

    if (new != NULL)
    {
        new->data = item;
        if (head == NULL)
        {
            new->link = NULL;
            head = new;
        }
        else
        {
            new->link = head;
            head = new;
        }
    }
    else
    {
        printf("MEMORY UNDERFLOW\n");
    }
}

void insert_end()
{
    int item;

    printf("Enter data :");
    scanf("%d", &item);

    new = (node *)malloc(sizeof(node));

    if (new != NULL)
    {
        new->data = item;
        if (head == NULL)
        {
            new->link = NULL;
            head = new;
        }
        else
        {
            ptr = head;
            while (ptr != NULL)
            {
                ptr = ptr->link;
            }
            new->link = NULL;
            ptr->link = new;
        }
    }
    else
    {
        printf("MEMORY UNDERFLOW\n");
    }
}
void insert_any() {}

void delete_front()
{
    if (head != NULL)
    {
        temp = head;
        head = head->link;
        free(temp);
    }
    else
    {
        printf("UNDERFLOW\n");
    }
}
void delete_end()
{
    ptr = head;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->link;

        if (ptr->link == NULL)
        {
            temp->link = NULL;
            free(ptr);
        }
    }
}
void delete_any() {}

void display()
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        ptr = head;
        printf("LINKED LIST :");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}