//
// Created by HUAWEI on 1/1/2023.
//
#include "stdio.h"
#include "stdlib.h"

const int MAXOFSTACK = 10;
struct stack {
    int arr[MAXOFSTACK];
    int top ;

};

typedef struct stack st;

int IsStackFUll(st* myStack){
    if (myStack->top == MAXOFSTACK-1){
        return 1;
    } else {
        return 0;
    }
}

int isStackEmpty (st* myStack){
    if (myStack->top == -1){
        return 1;
    } else {
        return 0;
    }
}
void CreatEmptyStack(st* myStack){
    myStack->top = -1;
}


void push(st* myStack, int value){
    if (IsStackFUll(myStack)){
        printf("The stack is FULL!\n");
    } else {
        myStack->top ++;
        myStack->arr[myStack->top]= value;
    }
}

void pop(st* myStack){
    if (isStackEmpty(myStack)){
        printf("The stack is EMPTY!!\n");
    } else {
        printf("Pop from stack data is: %d\n", myStack->arr[myStack->top]);
        myStack->top --;
    }
}
int main(){

    st* myStack = (st*)malloc(sizeof (st));
    CreatEmptyStack (myStack);
    push (myStack, 10);
    push (myStack, 15);
    push (myStack, 1);
    push (myStack, 110);
    push (myStack, 22);
    push (myStack, 9);
    push (myStack, 8);
    push (myStack, 7);
    push (myStack, 6);
    push (myStack, 4);
    //printf( "top is : %d\n", myStack->top);
    for (int i= myStack->top; i>-1 ;i-- ){
        pop(myStack);
    }

    return 0 ;
}