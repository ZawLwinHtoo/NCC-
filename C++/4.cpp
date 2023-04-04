//
// Created by HUAWEI on 11/26/2022.
//
#include "stdio.h"

int main(){
    int i, number[10], total=0;
    printf("Enter 10 numbers:");
    for(i=0; i<10; i++){
        scanf("%d",number+i);
        // &number[i]
        total += *(number+i);
        // total = total+ number[i]
        // total += number[i]

    }

    printf("Total number:%d\n",total);

    for(int x=0; x<10; x++){
        printf("Your data at index %d =%d,  MemoryAddress =%X\n",x,number[x], &number[x]);
    }

    return 0;
}