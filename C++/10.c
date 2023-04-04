#include "stdio.h"
#include "stdlib.h"
#include "time.h"
void generateChar();
void Counting();
int Arr[26]={0,0,0,0,0,0,0,0,0,00,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void dataPrint();
int biggest();
void numberCounting();
void writingInFile();

int main (){
    generateChar();
    Counting();
    dataPrint();
    int index =  biggestElement();
    printf("biggest Element Value = %d\n", index);
    //numberCounting();
    writingInFile();
    printf("THIS IS THE FUCKING END OF THE PROGRAM.");
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
    while (i<400){
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
        //printf("%d  %c\n",i,c); i++;
        int index = c-97;
        Arr[index]++;
        //printf("Index: %d\n", index);
        c= fgetc(fptr);

    }
    printf("Hello world\n\n");

    fclose(fptr);
}

void dataPrint() {
        int alpha = 97;
        for (int i = 0; i < 26; i++) {
            printf("No%d: %c = %d\n", i,  alpha, Arr[i]);
            alpha++;
        }
}

int biggestElement(){

    int bigElement = 0;
    for (int i=0; i<26; i++){

        if ( Arr[i] > bigElement){

            bigElement= Arr[i];
        }

    }
    return bigElement;
}

void numberCounting(){
    int alpha=97;
    int index= biggestElement();
    for (int i=0; i<index; i++){
        for (int j=0; j<26; j++){
            if (Arr[j] >0){
                printf("%c  ", j+alpha);
                Arr[j]= Arr[j]-1;
            }
            else {
                printf("   ");
            }
        }
        printf("\n");

    }
}

void writingInFile(){
    FILE *fptr;
    fptr = fopen("FILE", "w");
    fclose(fptr);
    FILE *fptr2;
    fptr2= fopen("FILE", "a");
    if (fptr2 == NULL){
        printf("Something went wrong");
    } else{

        int alpha=97;
        int index= biggestElement();
        for (int i=0; i<index; i++){
            for (int j=0; j<26; j++){
                if (Arr[j] >=0){
                    fprintf(fptr2, "%c  ", j+alpha);
                    Arr[j]= Arr[j]-1;
                }
                else {
                   fprintf(fptr2, "%c%c%c", ' ', ' ', ' ' );
                }
            }
            fprintf(fptr2, "%c", '\n');

        }
    }
    fclose(fptr2);

}