//
// Created by HUAWEI on 11/26/2022.
//
#include "stdio.h"
void swap(int *d1, int *d2);
int main() {
    int data1=10;
    int data2=20;
    printf("BEFORE SWAP\n");
    printf("This is data1:%d\n",data1);
    printf("This is data2:%d\n",data2);
    swap(&data1,&data2);   //pass by reference
    printf("AFTER SWAP\n");
    printf("This is data1:%d\n",data1);
    printf("This is data2:%d\n",data2);


    return 0;

}

void swap(int *d1, int *d2){
    int tempo;
    tempo = *d1;
    *d1 = *d2;
    *d2 = tempo;
}

