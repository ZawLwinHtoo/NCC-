#include "stdio.h"
#include "stdlib.h"
#include "time.h"
void generateChar();
void Counting();
int Arr[26]={0,0,0,0,0,0,0,0,0,00,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void dataPrint();

int main (){
    generateChar();
    Counting();
    dataPrint();
    return 0;
}

void generateChar(){
    FILE *fptr;
    fptr= fopen("4assign.txt", "w");
    fclose(fptr);

    FILE *fptr2;
    fptr2 = fopen("4assign.txt", "a");
    int i=0;
    srand(time(NULL));
    while (i<100){
        while (i<100){
            int data = rand()%123;
            if (data>96){
                fprintf(fptr2,"%c",data);
                i++;
            }
        }

        fclose(fptr2);
    }

    void Counting() {
        FILE *fptr;
        fptr= fopen("4assign.txt", "r");
        char c = fgetc(fptr);
        int i;
        while (!feof(fptr)) {
            printf("%d  %c\n",i,c); i++;
            int index = c-97;
            Arr[index]++;
            printf("Index: %d\n", index);
            c= fgetc(fptr);

        }
        printf("Hello world\n\n");
    }

    void dataPrint() {
        int alpha = 97;
        for (int i = 0; i < 26; i++) {
            printf("%c   %d\n", alpha, Arr[i]);
            alpha++;
        }
    }