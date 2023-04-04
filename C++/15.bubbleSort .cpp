//
// Created by HUAWEI on 12/31/2022.
//
#include "stdio.h"
#include "stdlib.h"

void bubbleSort (int Arr[], int size){

    for (int i=0 ; i<size-1; i++){

        for (int j=0; j<size-1-i    ; j++){

            if (Arr[j] > Arr[j+1]){
                int temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }

}

int main(){

    int arr[]= {2,4,6,7,8,9,1,97,87,44};
    int ArrSize = sizeof arr/ sizeof arr[1];
    bubbleSort(arr, ArrSize);
    for (int k=0 ; k<ArrSize; k++){
        printf(" %d : data: %d \n", k,  arr[k]);
    }

    return 0 ;
}