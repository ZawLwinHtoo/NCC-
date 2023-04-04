//
// Created by HUAWEI on 11/26/2022.
//

#include "stdio.h"
int main() {
    int i;
    int count;
    FILE *fptr;
    int fArray[100];
    FILE *fptr1;
    fptr1= fopen("ABCD.txt", "w");
    fclose(fptr1);
    fptr = fopen("ABCD.txt", "a");

    if (fptr == NULL) {
        printf("[-] Something went wrong! Plz try again!");
    } else {
        printf("a;djf\n");

        for (i = 1; i <= 100; i++) {

            fprintf(fptr, "%d%c", i, '\n');
        }

        fclose(fptr);

        fptr = fopen("ABCD.txt", "r");
        for(int i=0; i<100; i++) {
                fscanf(fptr, "%d\n", &fArray[i]);
        }
        fclose(fptr);

        for (i=0; i<100; i++){
            printf("Data at Index%d = %d\n", i, fArray[i]);
        }
    }
    return 0;
}