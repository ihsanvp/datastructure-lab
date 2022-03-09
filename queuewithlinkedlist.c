#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} node ;

node* front = NULL;
node* rear = NULL;
node* temp = NULL;

void enqueue();
void dequeue();
void display();

void main() {
	int choice, run = 1;

	while(run) {
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter Choice [1/2/3/4] :");
		scanf("%d", &choice);

		switch(choice) {
			case 1 :
				enqueue();
				break;
			case 2 :
				dequeue();
				break;
			case 3 :
				display();
				break;
			case 4 :
				run = 0;
				break;
			default :
				printf("Error : Invalid choice");
		}				
	}
}

void enqueue() {
	int data;
	printf("Enter data :");
	scanf("%d", &data);
	temp = (node*) malloc(sizeof(node));
	temp->data = data;
	temp->link = NULL;

	if (front == NULL && rear == NULL) {
		rear = temp;
		front = temp;
	} else {
		rear->link = temp;
		rear = temp;
	}
}

void dequeue() {
	if (front == NULL) {
		printf("Error : ")
	}
}
