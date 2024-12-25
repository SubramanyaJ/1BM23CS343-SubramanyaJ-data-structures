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
	memset(new, 0, sizeof(struct Node));

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
	if(!head){
		printf("Linked list empty!\n");
		return;
	}
	struct Node *ptr;
	for(ptr = head; ptr->next != NULL; ptr = ptr->next){
		printf("%d at %p\n", ptr->data, ptr);
	}	printf("%d at %p\n", ptr->data, ptr);
	}	//	Display
	
struct Node *naturalHelper(int num){
	struct Node *head = newNode(0);
	struct Node *ptr = head;
	for(int i = 1; i < num; i++){
		ptr->next = newNode(i);
		ptr = ptr->next;
	}
	return head;
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
		printf("Enter your choice :\n1. Create a linked list of size n\n2. deleteStart\n3. deleteEnd\n4. display\n5. Exit\n");
		scanf("%d", &choice);
		switch (choice){
			case (1):
				printf("Enter n : ");
				scanf("%d", &val);
				head = naturalHelper(val);
				break;
			case (2):
				head = deleteStart(head);
				break;
			case (3):
				deleteEnd(head);
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
