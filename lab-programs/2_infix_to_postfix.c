#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10
int stack[MAX];
int top = -1;

bool isEmpty(){
    if(top == -1){
        return true;
    }   return false;
}
bool isFull(){
    return top == (MAX-1);
}

void push(int value){
    if(isFull()){
        return;
    }
    stack[++top] = value;
}

int pop(){
    if(isEmpty()){
        return -1;
    }
    return stack[top--];
}

int getPrecedence(char ch){
    switch (ch){
        case '^':
            return 2;
        case '*':
        case '/':
        case '%':
            return 1;
        case '+':
        case '-':
        return 0;
    }
}

char getAssociativity(char ch){
    if(ch == '^'){
        return 'R';
    }   return 'L';
}

void *infixToPostfic(char * str){

    char res[MAX], stk[MAX];
    int rptr = -1;
    int sptr = -1;
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        char ch = str[i];
        
        if(         // Case 1 : an operand
            ch >= 'a' && ch <= 'z'
            || ch >= 'A' && ch <= 'Z'
            || ch >= '0' && ch <= '9'
        ){
            res[++rptr] = ch;
        }

        else if(    // Case 2 : (
            ch == '('
        ){
            stk[++sptr] = ch;
        }
        else if(    // Case 3 : )
            ch == ')'
        ){
            while(sptr != -1 | stk[sptr] != '('){
                res[++rptr] = str[sptr--];
            }   sptr--;
        }
        else{       // Case 4 : Operand
            while(
                sptr >= 0 && getPrecedence(ch) < getPrecedence(stk[sptr])
                || sptr >= 0 && getPrecedence(ch) == getPrecedence(stk[sptr]) && getAssociativity(ch) == 'L'
            ){
                    res[++rptr] = stk[sptr--];
            }       stk[++sptr] = ch;   
        }

    }
    while(sptr >= 0){
        res[++rptr] = stk[sptr--];
    }
    res[++rptr] = '\0';

    puts(res);

}

int main(){

    char ch[MAX];
    printf("Enter your expression :\n");
    fgets(ch, MAX, stdin);
    
    printf("Postfix expression is : \n");
    infixToPostfic(ch);
    
    return 0;
}
