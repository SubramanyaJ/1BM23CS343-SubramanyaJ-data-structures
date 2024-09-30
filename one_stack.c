/*
Write a program to simulate the working of stack using an
array with the following:
a) Push
b) Pop
c) Display
The program should print appropriate messages for stack
overflow, stack underflow
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int value){
	if(top == MAX - 1){
		fprintf(stderr, "Stack overflow!\n");
		return;
	}
	stack[++top] = value;
	return;
}

int pop(){
	if(top == -1){
		fprintf(stderr, "Stack underflow!\n");
		return 0;
	}
	return stack[top--];
}

void peek(){
	if(top == -1){
		fprintf(stderr, "Stack is empty!\n");
		return;
	}
	fprintf(stdout, "%d\n", stack[top]);
	return;	
}

void display(){
	if(top == -1){
		fprintf(stderr, "Stack underflow!\n");
		return;
	}
	for(int i = 0; i <= top; i++){
		fprintf(stdout, "%d ", stack[i]);
	}
}


int main(){
	int pushval = 0, popval = 0;
	int choice = 0;
	printf("Enter your choice : \n");
	while(choice != 5){
		printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
		scanf("%d", &choice);
		switch (choice){
		case 1:
			printf("Enter element to push : ");
			scanf("%d", &pushval);
			push(pushval);
			printf("Value pushed.");
			break;
		case 2:
			popval = pop();
			printf("%d\n", popval);
			break;
		case 3:
			peek();
			break;
		case 4:
			display();	
			break;
		case 5:
			break;
		deafult:
			print("Invalid option!\n");
		}
	}
	return 0;
}














