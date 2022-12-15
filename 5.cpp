//
// Created by HUAWEI on 11/26/2022.
//
#include "stdio.h"
int main() {
    int arr[5]={10,20,30,40,50};
    int *ptr ;
    ptr = &arr[3];

    printf("Value:%d\n",*ptr);
    printf("Value:%d\n",*(ptr+1));
    printf("Value:%d\n",*(ptr-1));

    return 0;
}