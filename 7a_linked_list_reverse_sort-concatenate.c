#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *newNode(int value){
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new->data = value;
    new->next = NULL;
    return new;
}

struct Node *insertHead(struct Node *head, int value){
    struct Node *new = newNode(value);
    new->next = head;
    new->data = value;
    return new;
}

void insertEnd(struct Node *head, int value){
    struct Node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode(value);
}

void insertPosition(struct Node *head, int value, int position){
    struct Node *ptr = head;
    for(int i = 2; i < position; i++){
        ptr = ptr->next;
    }
    struct Node *temp = ptr->next->next;
    ptr->next = newNode(value);
    ptr->next->next = temp;
    return;
}

struct Node *natural(){
    struct Node *new = newNode(0);
    int i = 1;
    struct Node *ptr;
    for(struct Node *ptr = new; i < 10; i++){
        ptr->next = newNode(i);
        ptr = ptr->next;
    }
    return new;
}

struct Node *randomgen(){
    struct Node *new = newNode(0);
    int i = 1;
    struct Node *ptr;
    for(struct Node *ptr = new; i < 4; i++){
        ptr->next = newNode(rand() % 1000);
        ptr = ptr->next;
    }
    return new;
}

void display(struct Node *head){
    struct Node *ptr = head;
    while(ptr){
        printf("%d at %p\n", ptr->data, ptr);
        ptr = ptr->next;
    }
    printf("------------------------------\n");
    return;
}

struct Node *deleteHead(struct Node *head){
    struct Node *temp = head->next;
    free(head);
    return temp;
}

void deleteEnd(struct Node *head){
    struct Node *ptr = head;
    while(ptr->next->next){
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

void deletePosition(struct Node *head, int position){
    struct Node *ptr = head;
    for(int i = 2; i < position; i++){
        ptr = ptr->next;
    }
    struct Node *temp = ptr->next->next;
    free(ptr->next);
    ptr->next = temp;
}

struct Node *reverse(struct Node *head){

    struct Node *prev = NULL, *curr = head, *next;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}

void sort(struct Node *head){

    struct Node *curr = head, *index = NULL;

    while(curr){

        index = curr->next;
        while(index){
            if(curr->data > index->data){
                int temp = curr->data;
                curr->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        curr = curr->next;
    }


}

void concatenate(struct Node *head1, struct Node *head2){
    struct Node *ptr = head1;
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = head2;
}

int main(){
    //    struct Node *head = randomgen();
    struct Node *head = randomgen();

    display(head);

    sort(head);
    display(head);

    head = reverse(head);
    display(head);

    struct Node *head2 = randomgen();
    display(head2);
    concatenate(head, head2);
    display(head);

}
