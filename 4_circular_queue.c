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

#define circArr[MAX]
int front = -1;
int back = -1;
int errno = 0;

bool isFull(){
	if( (rear + 1) % MAX == front ){
		return true;
	}
	return false;
}

bool isEmpty(){
	if( front == rear == -1){
		return true;
	}
	return false;	
}

void enqueue(int data){

	if( isfull() ){
		fprintf(stderr, "The queue is full! Overflow\n");
		return;
	}	

	if( front == -1 ){
		front = 0;
	}

	rear = (rear + 1) % MAX;
	circArrr[rear] = data;

	printf("%d inserted.\n", data);
	return;
}

int dequeue(){

	if( isEmpty() ){
		fprintf(stderr, "The queue is empty! Underflow!\n");
		errno = 1;
		return -1;
	}
	
	int retval = circArr[front];

	if( front == rear ){
		front = rear = -1;
	}
	else{
		front = (front + 1) % MAX;
	}

	return data;
}
