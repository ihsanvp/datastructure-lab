#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} node;

node* top = NULL; 
node* temp = NULL;	

void push();
void pop();
void peek();
void display();

void main() {
	
	int run = 1, choice;

	do {	
		printf("--------------------------\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. DISPLAY\n");
		printf("4. PEEK\n");
		printf("5. EXIT\n");
		printf("Enter Choice [1/2/3/4/5] :");
		scanf("%d", &choice);

		switch(choice) {
			case 1 :
				printf("--------------------------\n");
				push();
				break;
			case 2 :
				printf("--------------------------\n");
				pop();
				break;
			case 3 :
				printf("--------------------------\n");
				display();
				break;
			case 4 :
				printf("--------------------------\n");
				peek();
				break;
			case 5 :
				run = 0;
				break;
			default :
				printf("--------------------------\n");
				printf("Error: Invalid Choice\n");		
		}		
	} while(run);
				
}

void push() {
	int data;

	printf("Enter data:");
	scanf("%d", &data);

	temp = (node*) malloc(sizeof(node));
	temp->data = data;
	temp->link = NULL;

	if (top != NULL) {
		temp->link = top;
	}

	top = temp;
	
	printf("Push: %d\n", data);
}

void pop() {
	if (top == NULL) {
		printf("Error: Stack Empty\n");
	} else {
		temp = top;
		top = top->link;
		printf("Pop: %d\n", temp->data);
		free(temp);
	}
}

void peek() {
	if (top == NULL) {
		printf("Error: Stack Empty\n");
	} else {
		printf("Peek: %d\n", top->data);
	}
}

void display() {
	if (top == NULL) {
		printf("Error: Stack empty\n");
	} else {
		temp = top;
		
		printf("Stack: [");
		while(temp != NULL) {
			printf("%d,", temp->data);
			temp = temp->link;
		}
		
		printf("]\n");
	} 
}
