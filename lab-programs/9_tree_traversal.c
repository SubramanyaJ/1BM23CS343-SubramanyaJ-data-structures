#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newnode(int value){
	struct Node *new = (struct Node *) malloc(sizeof(struct Node));
	new->right = NULL;
	new->left = NULL;
	new->data = value;
	return new;
}

void freetree(struct Node *root){
	if(root){
		freetree(root->right);
		freetree(root->left);
		free(root);
	}
}

struct Node *insert(struct Node *root, int value){
	if(root == NULL){
		return newnode(value);
	}
	if(value < root->data){
		root->left = insert(root->left, value);
	}
	else if(value > root->data){
		root->right = insert(root->right, value);
	}
	return root;
}

void traverse_inorder(struct Node *root){

	if(root == NULL){
		return;
	}

	traverse_inorder(root->left);
	printf("%d ", root->data);
	traverse_inorder(root->right);
	return;
}

void traverse_preorder(struct Node *root){

	if(root == NULL){
		return;
	}

	printf("%d ", root->data);
	traverse_preorder(root->left);
	traverse_preorder(root->right);
	return;
}

void traverse_postorder(struct Node *root){

	if(root == NULL){
		return;
	}

	traverse_postorder(root->left);
	traverse_postorder(root->right);
	printf("%d ", root->data);
	return;
}

void traverse_levelorder(struct Node *root){
	struct Node *queue[MAX];
	int front = -1, back = -1;
	struct Node *ptr = root;
	queue[++back] = ptr;
	while(front != back){
		ptr = queue[++front];
		printf("%d ", ptr->data);
		if(ptr->left){
			queue[++back] = ptr->left;
		}
		if(ptr->right){
			queue[++back] = ptr->right;
		}
	}
	putchar('\n');
}

int main() {
	struct Node* root = NULL;
	int choice, value;
	void (*fptr)(struct Node *);
	void(*arr[4])(struct Node *) = {&traverse_preorder, &traverse_inorder, &traverse_postorder, &traverse_levelorder};

	while (true) {
		printf("\nBinary Search Tree Operations:\n");
	        printf("1. Construct Binary Tree\n");
	        printf("2. Display (Pre-order Traversal)\n");
	        printf("3. Display (In-order Traversal)\n");
	        printf("4. Display (Post-order Traversal)\n");
	        printf("5. Display (Level-order Traversal)\n");
	        printf("6. Exit\n");
	        printf("Enter your choice: ");
	        scanf("%d", &choice);

	switch (choice) {
	case 1:
		root = NULL;
		printf("Enter the number of values to enter : ");
		scanf("%d", &choice);
				printf("Enter the values : \n");
		for(int i = 0; i < choice; i++){
			scanf("%d", &value);
			root = insert(root, value);
		}
                break;
	case 2:
	case 3:
	case 4:
	case 5:
		fptr = arr[choice - 2];
		fptr(root);
                break;
	case 6:
		freetree(root);
		return 0;
	default:
		printf("Invalid option!\n");
        }
    }

    return 0;
}

