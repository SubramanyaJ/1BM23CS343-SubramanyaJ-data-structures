#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int dequeue[MAX];
int back = -1;
int front = -1;
int value;

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