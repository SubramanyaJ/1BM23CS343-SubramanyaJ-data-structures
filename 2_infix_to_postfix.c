/*
WAP to convert a given valid parenthesized infix arithmetic 
expression to postfix expression. The expression consists of 
single character operands and the binary operators + (plus), - (minus), * (multiply) and / (divide) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prec(char c){
    if(c == '-' || c == '+'){
        return 1;
    }
    if(c == '*' || c == '/'){
        return 2;
    }
    if(c == '!' || c == '~'){
        return 1;
    }
    return -1;
}

char assoc(char c){
    if(c == '!'|| c == '~'){
        return 'R';
    }
    else{
        return 'L';
    }
}

void infixToPostfix(char *set){
    int len = strlen(set);

    char result = (char *) malloc(sizeof(char)(len+1));
    char stack = (char *) malloc(sizeof(char)(len));

    int resultIndex = 0;
    int stackIndex = -1;

    for(int i = 0; i < len; i++){

        char c = set[i];

        if( c >= 'a' && c <= 'z' ||
            c >= 'A' && c <= 'Z' ||
            c >= '0' && c <= '9'
        ){
            result[resultIndex++] = c;
        }

        else if(c == '('){
            stack[++stackIndex] = c;
        }

        else if(c == ')'){
            while(( stackIndex >= 0 && 
                    stack[stackIndex] != '(')){
                        result[resultIndex++] = stack[stackIndex--];
            }
            stackIndex--;
        }

        else{

            while(
                (stackIndex >= 0 && (prec(c) <= prec(stack[stackIndex]))) ||
                (prec(c) == prec(stack[stackIndex]) && assoc(c) == 'L')
            ){
                result[resultIndex++] = stack[stackIndex--];
            }
            stack[++stackIndex] = c;

        }

    }



    while(stackIndex >= 0){
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0';
    puts(result);
    free(result);
    free(stack);

}

int main(){
    
    char exp[] = "a+b*c/d";
    infixToPostfix(exp);
    return 0;
}
