#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} node ;

node* root = NULL;
node* temp = NULL;
node* ptr = NULL;
node* parent = NULL;


void insert();
void preorder(node*);
void inorder(node*);
void postorder(node*);

void main() {
	int choice;

	while(choice != 5) {
		printf("1.Insert\n2.PreOrder Traversal\n3.InOrder Traversal\n4.PostOrder Traversal\n5.Exit\n");
		printf("Enter Choice [1/2/3/4/5] :");
		scanf("%d", &choice);
		switch(choice) {
			case 1 :
				insert();
				break;
			case 2 :
				printf("Preorder : ");
				preorder(root);
				printf("\n");
				break;
			case 3 :
				printf("Inorder : ");
				inorder(root);
				printf("\n");
				break;
			case 4 :
				printf("Postorder : ");
				postorder(root);
				printf("\n");
				break;
			case 5 :
				break;
			default :
				printf("Please enter valid choice\n");							
		}
	}	
}

void insert() {
	int item;

	printf("Enter data :");
	scanf("%d", &item);
	
	temp = (node*) malloc(sizeof(node));
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;

	if (root == NULL) {
		root = temp;		
	} else {
		ptr = root;
		while(ptr != NULL) {
			parent = ptr;
			
			if (item > ptr->data) {
				ptr = ptr->right;
				if (ptr == NULL) {
					parent->right = temp;
				}
			} else {
				ptr = ptr->left;
				if(ptr == NULL) {
					parent->left = temp;
				}
			}			
		}
	}	
}

void preorder(node* ptr) {
	if (ptr != NULL) {
		printf("%d ", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);	
	}
}

void inorder(node* ptr) {
	if (ptr != NULL) {
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}
}

void postorder(node* ptr) {
	if (ptr != NULL) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ", ptr->data);
	}
}
