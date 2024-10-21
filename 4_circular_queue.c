/**
 *  WAP to simulate the working of a circular queue of
 *  integers using an array. Provide the following operations:
 *  Insert, Delete & Display
 *  The program should print appropriate messages for queue
 *  empty and queue overflow conditions in C
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define DB (printf("control reached here\n"))

int circArr[MAX];
int front = -1;
int back = -1;
int myerrno = 0;

bool isFull(){
	if( (back + 1) % MAX == front ){
		return true;
	}
	return false;
}

bool isEmpty(){
	if( front == -1){
		return true;
	}
	return false;	
}

void enqueue(int data){

	if( isFull() ){
		fprintf(stderr, "The queue is full! Overflow\n");
		return;
	}	

	if( front == -1 ){
		front = 0;
	}

	back= (back+ 1) % MAX;
	circArr[back] = data;

	printf("%d inserted.\n", data);
	return;
}

int dequeue(){

	if( isEmpty() ){
		fprintf(stderr, "The queue is empty! Underflow!\n");
		myerrno = 1;
		return -1;
	}
	
	int retval = circArr[front];

	if( front == back){
		front = back = -1;
	}
	else{
		front = (front + 1) % MAX;
	}

	return retval;
}


void display(){
	
	if( isEmpty() ){
		fprintf(stderr, "The queue is empty!\n");
		return;
	}

	int i;
	
	for(int i = front; i != back; i = (i+1) % MAX){
		printf("%d ", circArr[i]);
	}	printf("%d \n", circArr[back]);

}

int main(){

	int casev = 0;
	int value = 0;

	while(true){
	
		printf("\nEnter an option :\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

		scanf("%d", &casev);
	
		switch(casev){
			
			case 1:
				printf("Enter value : ");
				scanf("%d", &value);
				enqueue(value);
				break;
			case 2:
				value = dequeue();
				if(myerrno){
					myerrno  = 0;
					break;
				}
				printf("Returned value is %d\n", value);
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default:
				printf("Invalid option!\n");
				break;
	
			
		}	// End of switch case
		

	}		// End of while-true
	return 0;
}	// End of main
