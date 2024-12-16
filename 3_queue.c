/* *
 * 3a) WAP to simulate the working of a queue of integers
 * using an array. Provide the following operations: Insert,
 * Delete, Display
 * The program should print appropriate messagesfor queue
 * empty and queue overflow conditions
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#define MAX 10

int queue[MAX];
int front = -1;
int back = -1;

void addQueue(int element){
	
	if(front == MAX - 1){
		fprintf(stderr, "Queue is full!\n");
		return;
	}
		
	queue[++front] = element;
}

int deQueue(void){
	
	if(back == front){
		fprintf(stderr, "Queue is empty!\n");
		return -1;
	}

	return (queue[++back]);

}

void displayQueue(void){
	if(back == front){
		fprintf(stderr, "Queue is empty!\n");
		return;
	}

	for(int i = back + 1; i <= front; i++){
		printf("%d ", queue[i]);
	}
}

int main(){
	
	int casev = 0;
	int value = 0;
	while(true){
		printf("Enter an option :\n1. Add to queue\n2. Delete from queue\n3. Display queue\n4. Quit\n");
		scanf("%d", &casev);
		switch (casev){
		case 1: 
			printf("Enter value\n");
			scanf("%d", &value);
			addQueue(value);
			break;
		case 2:
			value = deQueue(); 
			printf("%d was returned\n", value);
			break;
		case 3:
			displayQueue();
			break;
		case 4:
			return 0;

		case 5:
			printf("Invalid option!\n");
			break;

		}	// End of switch block
	}		// End of while block
	return 0;	
}			// End of main(), program
