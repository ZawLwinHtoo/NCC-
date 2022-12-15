//
// Created by HUAWEI on 12/11/2022.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char scanner[1000000];
char searcher[100];
void findingData1();
void loading();


int main(){
    loading();
    findingData1();



    return 0 ;
}


void loading() {
    int index = 0;
    int data = 0;
    FILE *fptr;
    fptr = fopen("words.txt", "r");

    while (fscanf(fptr, "%d", &data) == 1) {
        scanner[index] = data;
        index++;
    }

    fclose(fptr);
}


void findingData1(){
    int i=0;
    int key=0;
    /* FILE *fptr1;
    fptr1 = fopen("words.txt", "w");
    fclose(fptr1); */

    while (key < 1) {
        FILE *fptr;
        fptr = fopen("words.txt", "r");
        if (fptr == NULL){
            printf("File missing.\nPlz try again!");
            exit(-1);
        } else {

            printf("Type the word you want to search:");
            scanf("%s", searcher);
            while (fscanf(fptr, "%s", scanner) == 1) {
                if (strstr(scanner, searcher) != 0) {
                    i++;
                }
            }
        }
        fclose(fptr);
        printf("We found the word ( %s ) in the file ' %d ' times\n", searcher, i);
        i= 0 ;

        printf("Type 0 to find again or 1 to exit");
        scanf ("%d", &key);
        printf("\n");
        if(key>0){
            break;
        }
        else{
            key<0;
        }
    }
}
