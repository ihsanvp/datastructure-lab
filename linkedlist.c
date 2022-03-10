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
node *parent = NULL;

void insert_front();
void insert_end();
void insert_pos();
void delete_front();
void delete_end();
void delete_pos();
void display();

node *createNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode != NULL)
    {
        newnode->data = data;
        newnode->link = NULL;
    }

    return newnode;
}

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
            insert_pos();
            break;

        case 4:
            delete_front();
            break;

        case 5:
            delete_end();
            break;

        case 6:
            delete_pos();
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

    new = createNode(item);

    if (new != NULL)
    {
        if (head == NULL)
        {
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

    new = createNode(item);

    if (new != NULL)
    {
        if (head == NULL)
        {
            head = new;
        }
        else
        {
            ptr = head;
            while (ptr != NULL)
            {
                parent = ptr;
                ptr = ptr->link;
            }
            parent->link = new;
        }
    }
    else
    {
        printf("MEMORY UNDERFLOW\n");
    }
}
void insert_pos()
{
    int item, pos, i;

    printf("Enter data :");
    scanf("%d", &item);

    printf("Enter position :");
    scanf("%d", &pos);

    new = createNode(item);

    if (new != NULL)
    {
        if (head == NULL)
        {
            head = new;
        }
        else
        {
            ptr = head;
            i = 0;
            while (i < pos)
            {
                if (ptr->link == NULL)
                {
                    parent = ptr;
                    ptr = NULL;
                    break;
                }
                parent = ptr;
                ptr = ptr->link;
                i++;
            }
            if (ptr == head) // CASE 1 - first position
            {
                new->link = head;
                head = new;
            }
            else if (ptr == NULL) // CASE 2 - last position
            {
                parent->link = new;
            }
            else // CASE 3 - middle position
            {
                new->link = parent->link;
                parent->link = new;
            }
        }
    }
    else
    {
        printf("MEMORY UNDERFLOW\n");
    }
}

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
    if (head != NULL)
    {
        if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            ptr = head;
            while (ptr != NULL)
            {
                parent = ptr;
                ptr = ptr->link;
                if (ptr->link == NULL)
                {
                    break;
                }
            }
            temp = parent->link;
            parent->link = NULL;
            free(temp);
        }
    }
    else
    {
        printf("UNDERFLOW\n");
    }
}

void delete_pos()
{
    int pos, i;
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("Enter position to delete :");
        scanf("%d", &pos);

        ptr = head;
        i = 0;
        while (i < pos)
        {
            if (ptr->link == NULL)
            {
                printf("node not found at position '%d'\n", pos);
                return;
            }
            parent = ptr;
            ptr = ptr->link;
            i++;
        }

        if (ptr == head) // CASE 1 - first position
        {
            head = ptr->link;
            free(ptr);
        }
        else if (ptr->link == NULL) // CASE 2 - last position
        {
            parent->link = NULL;
            free(ptr);
        }
        else // CASE 3 - middle position
        {
            parent->link = ptr->link;
            free(ptr);
        }
    }
}

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