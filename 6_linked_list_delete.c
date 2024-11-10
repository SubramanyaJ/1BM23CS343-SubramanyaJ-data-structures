#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *newNode(int value){
	struct Node *new = (struct Node *) malloc(sizeof(struct Node));
	memset(new, 0, sizeof(new));

	new->data = value;
	new->next = NULL;
	return new;
}	// Create a new node
	
struct Node *insertStart(struct Node *head, int value){
	struct Node *newhead = newNode(value);
	newhead->next = head;
	return newhead;
}	// Inserts at begenning
	
void insertEnd(struct Node *head, int value){
	struct Node *ptr;
	for(ptr = head; ptr->next != NULL; ptr = ptr->next){
		// Traverse
	}
	ptr->next = newNode(value);
	return;
}	// Inserts at beginning
	
void displayData(struct Node *head){
	struct Node *ptr;
	for(ptr = head; ptr->next != NULL; ptr = ptr->next){
		printf("%d at %p", ptr->data, ptr);
	}	printf("%d at %p", ptr->data, ptr);
	}	//	Display
	
struct Node *naturalHelper(int num){
	struct Node *ptr = newNode(0);
	for(int i = 1; i < num; i++){
		ptr->next = newNode(i);
		ptr = ptr->next;
	}
	return ptr;
}

struct Node *deleteStart(struct Node *head){
	struct Node *ptr = head->next;
	free(head);
	return ptr;
}

void *deleteEnd(struct Node *head){
	struct Node *ptr = head;
	while(ptr->next->next){
		ptr = ptr->next;
	}
	free(ptr->next);
	ptr->next = NULL;
}

void deleteIndex(struct Node *head, int index){
	struct Node *ptr = head;
	for(int i = 1; i < index; i++){
		ptr = ptr->next;
	}
	struct Node *temp = ptr->next->next;
	free(ptr->next);
	ptr->next = temp;
	return;
}

int main(){
	int choice = 0;
	int val = 0;
	struct Node *head;
	while(true){
		printf("Enter a choice : \n");
		printf("1. Create a linked list of size n\n2. Insert at end\n4. Display\n5.Exit");
		scanf("%d", &choice);
		switch (choice){
			case (1):
				printf("Enter n : ");
				scanf("%d", &val);
				head = naturalHelper(val);
				break;
			case (2):
				printf("Enter value : ");
				scanf("%d", &val);
				head = insertStart(head, val);
				break;
			case (3):
				printf("Enter value : ");
				scanf("%d", &val);
				insertEnd(head, val);
				break;
			case (4):
				displayData(head);
				break;
			case (5):
				return 0;
			default:
				printf("Invalid option\n");

		}	// End of switch

	}	// End of while-loop

}	// End of main
