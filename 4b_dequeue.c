#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int dequeue[MAX];
int back = -1;
int front = -1;
int value;

void display(){
    for(int i = back; back < front; i++){
        printf("%d ", dequeue[i]);
    }
}

bool isEmpty(){
    if(front == -1){
        return true;
    }   return false;
}

bool isFull(){
    if((back+1)%MAX == front){
        return true;
    }   return false;
}

void insertFront(int value){

    if(isFull()){
        printf("Queue is full!\n");
        return;
    }
    if(isEmpty()){
        front = back = 0;
    }
    else{
        front = (front - 1 + MAX) % MAX;
    }
    dequeue[front] = value;
    return;
}

void insertRear(int value){

    if(isFull()){
        printf("Queue is full!\n");
        return;
    }

    if(isEmpty()){
        front = back = 0;
    }
    else{
        back = (back + 1) % MAX;
    }

    dequeue[back] = value;
    return;
}

int deleteFront(){

    if(isEmpty()){
        printf("Queue is empty!\n");
        return -1;
    }

    int retval = dequeue[front];
    if(front == back){
        front = back = -1;
    }
    else{
        front = (front + 1) % MAX;
    }

    return retval;

}

int deleteRear(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return -1;
    }
    
    int retval = dequeue[back];
    if(front == back){
        front = back = -1;
    }
    else{
        back = (back + MAX - 1) % MAX;
    }

    return retval;

}

int main(){

	int casev = 0;
	int value = 0;

	while(true){
	
                printf("Enter an option :\n1. InsertFront\n2. InsertRear\n3. DeleteEnd\n4. DeleteFront\n5. Display\n6. Exit");

		scanf("%d", &casev);
	
		switch(casev){
			
			case 1:
				printf("Enter value : ");
				scanf("%d", &value);
				insertFront(value);
				break;
                        case 2:
				printf("Enter value : ");
				scanf("%d", &value);
				insertRear(value);
				break;
                                
			case 3:
				value = deleteRear();
				printf("Returned value is %d\n", value);
				break;
			case 4:
				value = deleteFront();
				printf("Returned value is %d\n", value);
				break;
			case 5:
                                display();
				break;
                        case 6:
                                return 0;
			default:
				printf("Invalid option!\n");
				break;
	
			
		}	// End of switch case
		

	}		// End of while-true
	return 0;
}	// End of main
