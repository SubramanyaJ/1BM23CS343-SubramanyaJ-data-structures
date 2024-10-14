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
	return;
}

int deQueue(){
	
	if(back == front){
		fprintf(stderr, "Queue is empty!\n");
		return -1;
	}

	return (queue[++back]);

}


int main(){
	
	int case = 0;
	int value = 0;
	while(true){
		
		switch (case){
		case 1: 
			printf("Enter a number to queue.\n");
			scanf("%d", &value);
			addQueue(value);
			break;
		case 2:
			value = deQueue(); 
			printf("The deQueue'd value is %d.\n", value);
		case 3:
			return 0;
		case 4:
			printf("Unknown option! Try again!\n");

		}
	}
	return 0;
}
