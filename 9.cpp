
#include "stdio.h"
#include "stdlib.h"
void InsertdataToFile();
void loading();
void printing();
int Arr[100];
int main(){
     InsertdataToFile();
     loading();
     printing();
    return 0;
}

void InsertdataToFile() {
    int i;

    FILE *fptr1;
    fptr1 = fopen("abc.txt", "w");
    fclose(fptr1);

    FILE *fptr;
    fptr = fopen("abc.txt", "a");
        if (fptr==NULL) {
            printf("Something went wrong!");
            exit(1);
        }
        else {
            for (i = 1; i <=100; i=i+1) {
                fprintf(fptr, "%d%c",i, 'c');
            }
        }
    fclose(fptr);
}

void loading() {
    int index = 0;
    int data = 0;
    FILE *fptr;
    fptr = fopen("abc.txt", "r");

    while (fscanf(fptr, "%d", &data) == 1) {
        Arr[index] = data;
        index++;
    }

    fclose(fptr);
}
