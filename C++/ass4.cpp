#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char scanner[1000000];
char searcher[100]="winhtut";
char searcher2[100]="NationalCyberCity";
void findingData1();
void loading();
void findingData2();

int main(){
     loading();
     findingData1();
    findingData2();


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


    FILE *fptr;
    fptr = fopen("words.txt", "r");
    if (fptr == NULL){
        printf("File missing.\nPlz try again!");
        exit(-1);
    } else {
            while (fscanf(fptr, "%s", scanner) == 1) {
                if (strstr(scanner, searcher) != 0) {
                    i++;
                }
            }
        }
        fclose(fptr);
        printf("We found the word ( %s ) in the file ' %d ' times\n", searcher, i);
        i=0;
}


void findingData2(){
    int i=0;
    int key=0;
    /*FILE *fptr1;
    fptr1 = fopen("words.txt", "w");
    fclose(fptr1); */


    FILE *fptr;
    fptr = fopen("words.txt", "r");
    if (fptr == NULL){
        printf("File missing.\nPlz try again!");
        exit(-1);
    } else {
        while (fscanf(fptr, "%s", scanner) == 1) {
            if (strstr(scanner, searcher2) != 0) {
                i++;
            }
        }
    }
    fclose(fptr);
    printf("We found the word ( %s ) in the file ' %d ' times\n", searcher, i);
    i=0;
}
