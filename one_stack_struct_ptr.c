#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Stack{
    int s[MAX];
    int top;
};

struct Stack *newStack(){
    struct Stack *new = (struct Stack*) malloc(sizeof(struct Stack));
    memset(new, 0, sizeof(struct Stack));
    new->top = -1;
    return new;
}

void push(struct Stack *stack, int value){
	if(stack->top == MAX - 1){
		fprintf(stderr, "Stack overflow!\n");
		return;
	}
	stack->s[++(stack->top)] = value;
	return;
}

int pop(struct Stack *stack){
	if(stack->top == -1){
		fprintf(stderr, "Stack underflow!\n");
		return;
	}
	return stack->s[(stack->top)--];
}

void peek(struct Stack *stack){
	if(stack->top == -1){
		fprintf(stderr, "Stack is empty!\n");
		return;
	}
	fprintf(stdout, "%d\n", stack->s[(stack->top)]);
	return;
}

void display(struct Stack *stack){
	if(stack->top == -1){
		fprintf(stderr, "Stack underflow!\n");
		return;
	}
	for(int i = 0; i <= stack->top; i++){
		fprintf(stdout, "%d ", stack->s[i]);
	}
}


int main(){

    struct Stack *stack;
    stack = newStack();

    int pushval = 0, popval = 0;
	int choice = 0;
	printf("Enter your choice : \n");
	while(choice != 5){
		printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
		scanf("%d", &choice);
		switch (choice){
		case 1:
			printf("Enter element to push : ");
			scanf("%d", &pushval);
			push(stack, pushval);
			printf("Value pushed.");
			break;
		case 2:
			popval = pop(stack);
			printf("%d\n", popval);
			break;
		case 3:
			peek(stack);
			break;
		case 4:
			display(stack);
			break;
		case 5:
			break;
		deafult:
			printf("Invalid option!\n");
		}
	}
	return 0;

}
