#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};

struct Node *newnode(int value){
	struct Node *new = (struct Node *) malloc(sizeof(struct Node));
	new->next = NULL;
	new->prev = NULL;
	new->data = value;
	return new;
}

void display(struct Node *head){
	struct Node *ptr = head;
        if(!(ptr)){
            printf("List is empty!\n");
            return;
        }
	while(ptr){
		printf("%d at %p\n", ptr->data, ptr);
		ptr = ptr->next;
	}
	printf("-------------------------\n");
}

void insertHead(struct Node **head, int value){
	if(*head == NULL){
		*head = newnode(value);
		return;
	}
	struct Node *new = newnode(value);
	(*head)->prev = new;
	new->next = *head;
	*head = new;
	return;
}

void insertEnd(struct Node **head, int value){
	if(*head == NULL){
		*head = newnode(value);
		return;
	}
	struct Node *ptr = *head;
	while(ptr->next){
		ptr = ptr->next;
	}
	ptr->next = newnode(value);
	ptr->next->prev = ptr;
	return;
}	

void insertPosition(struct Node **head, int value, int position){
	if(*head == NULL){
		*head = newnode(value);
		return;
	}
	if(position == 1){
		insertHead(head, value);
		return;
	}

	struct Node *ptr = *head;
	for(int i = 2; i < position; i++){
		if(ptr->next){
			ptr = ptr->next;
		}
		else{
			ptr->next = newnode(value);
			ptr->next->prev = ptr;
			return;
		}
	}
	struct Node *new = newnode(value);
	new->next = ptr->next;
	ptr->next = new;
	ptr->next->prev = ptr;
	return;
}

int main(){
    int choice = 0, value = 0, value2 = 0;
    struct Node *head = NULL;
    struct Node **headptr = &head;
    while(true){
        printf("Enter a choice :\n1. Create a new linked list\n2. Insert at beginning\n3. Insert at specific location\n4. Insert at end\n5. Display the linked list\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = NULL;
                printf("A new linked list has been created!\n");
                break;
            case 2:
                printf("Enter the value : ");
                scanf("%d", &value);
                insertHead(headptr, value);
                break;
            case 3:
                printf("Enter the value : ");
                scanf("%d", &value);
                printf("Enter the position : ");
                scanf("%d", &value2);
                insertPosition(headptr, value, value2);
                break;
            case 4:
                printf("Enter the value to enter : ");
                scanf("%d", &value);
                insertEnd(headptr, value);
                break;
            case 5:
                display(head);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}
