//
// Created by HUAWEI on 1/1/2023.
//
#include "stdio.h"


int min( int first, int second ){
    if (first<second){
        return first;
    } else
        return second;
}

int jumpSearch ( int arr[], int size , int key){
    int add;
    if (size%2 == 0){
        add = 4;
    } else {
        add= 3;
    }
    int previous;
    int step=add;

    while (arr[min(step, size)-2]< key){
        if (arr[size-1]==key){
            return size-1;
        }
        if (arr[step-1]==key){
            return step-1;
        }
        previous = step;
        step = size + add ;
        if (previous > size){
            return -1;
        }
    }


    int middle = previous+ add/2;
    if (arr[middle] > key){
        for (int j=previous; j<middle; j++){
            if (arr[j]==key){
                return j;
            }
        }
    }else{
        for (int k=middle; k<step; k++){
            if (arr[k]==key){
                return k;
            }
        }
    }


      /* for (int i=previous; i<step ; i++){

        if (arr[i]==key){
            return i;
        }
    } */

    return -1 ;

}
int main(){

    int Arr[]={2,4,6,7,8,9,12,34,57,88,111,146,222, 234,266, 456, 555, 666};
    int size = sizeof (Arr)/ sizeof (Arr[1]);
    int toFind ;
    scanf ("%d", &toFind);
    int indexNumber= jumpSearch(Arr, size, toFind);
    if (indexNumber != -1) {
        printf("We found\n");
        printf("index number %d : data %d", indexNumber, Arr[indexNumber]);
    } else
        printf("Not found");

    return 0 ;
}