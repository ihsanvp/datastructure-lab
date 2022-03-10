#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *link;
} node;

node *top = NULL;
node *temp = NULL;

void push();
void pop();
void peek();
void display();

void main()
{
	int choice;

	printf("STACK USING LINKED LIST\n");
	printf("1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n");

	do
	{
		printf("Enter Choice [1/2/3/4/5] :");
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
			display();
			break;

		case 4:
			peek();
			break;

		case 5:
			break;

		default:
			printf("Error: Invalid Choice\n");
		}
	} while (choice != 5);
}

void push()
{
	int data;

	printf("Enter data:");
	scanf("%d", &data);

	temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->link = NULL;

	if (top != NULL)
	{
		temp->link = top;
	}

	top = temp;
}

void pop()
{
	if (top == NULL)
	{
		printf("UNDERFLOW\n");
	}
	else
	{
		temp = top;
		top = top->link;
		free(temp);
	}
}

void peek()
{
	if (top == NULL)
	{
		printf("UNDERFLOW\n");
	}
	else
	{
		printf("Top Element : %d\n", top->data);
	}
}

void display()
{
	if (top == NULL)
	{
		printf("UNDERFLOW\n");
	}
	else
	{
		temp = top;

		printf("Stack: ");
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->link;
		}

		printf("\n");
	}
}
