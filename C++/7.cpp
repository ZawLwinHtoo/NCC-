//
// Created by HUAWEI on 11/26/2022.
//
#include "stdio.h"

void passByPointer(int *Value);
int main(){
    int *p;
    int data=20;

    p=&data;

    passByPointer(p);
    printf("This is passByPointer:%d\n",*p);
    printf("This is passByPointer but with data variable:%d\n",data);

    return 0;
}

void passByPointer(int *Value){
    (*Value)++;

}