//
// Created by HUAWEI on 1/19/2023.
//
#include "stdio.h"


unsigned long long int recursion(int a){
    if(a==1){
        return 1;
    } else {
        return a * recursion(--a);
    }
}
int main(){

    int factor ;

    for (int i = 0 ; i<5 ; i++){

        scanf ("%d", &factor);
        printf("%u\n", recursion(factor));

    }

    return 0;
}