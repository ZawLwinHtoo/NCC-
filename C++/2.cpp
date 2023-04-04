//
// Created by HUAWEI on 11/16/2022.
//
#include "stdio.h"
int main() {

    int myArr[13]={1,2,3,4,5,2,7,8,9,10,2,12,13};
    int toFind = 2;
    int i=0 ;
    int count=0 ;
    int myArr2[10];
    for (i=0; i<13; i++){
        if (myArr[i]==toFind){
            myArr2[count]=i;
            count++ ;
            printf("We found at:%d\n",i);
        }
    }
    if(count==0){
        printf("Not found ") ;
    } else{
        printf("We found");
        printf("%d",count) ;
    }

    printf("\n %d",myArr2   [count]);
    return 0 ;
}