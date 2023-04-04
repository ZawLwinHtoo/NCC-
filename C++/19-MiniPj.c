//
// Created by HUAWEI on 1/20/2023.
//

#include "stdio.h"
#include "stdlib.h"
#define SIZE 50
struct worker {
    int id;
    int age;
    char name[30];
    char email[50];
    char pw[50];
};

int efound = -1;
int pfound = -1;
int globalIndex = 0;

struct worker info[SIZE];
void printingAllData();
void login();
int charCounting(char toCount[50]);
void myStrNameCpr(char userInputData[50]);
int gmailValidation(char tester[50]);
void passCheck(char pass[50], int userIndex);
void recordingAllDataToAFile();
void userActionSector();
void loadingDataFromFile();
void lobby();
void registration();

int main(){

     loadingDataFromFile();
     printingAllData();
     lobby();
    return 0 ;
}


void lobby(){
    int lob;
    printf("This is lobby sector\n");
    printf("Press 1 to log in.\n");
    printf("Press 2 to register.\n");
    printf("Press 3 to exit.\n");
    scanf(" %d", &lob);

    if(lob==1){
        login();
    } else if (lob==2){
        registration();
    } else if(lob==3){
        exit(1);
    } else {
        printf("Invalid option. Plz try again\n");
        lobby();
    }
}
void printingAllData(){

    for (int i=0; i<globalIndex; i++){
        printf("id:%d-name:%s-age:%d-email:%s-pw:%s\n", info[i].id, info[i].name, info[i].age, info[i].email, info[i].pw);
    }
}

void login(){

    char lEmail[50];
    char lPw[50];
    printf("This is login\n");

    printf("Enter email:");
    scanf(" %[^\n]", &lEmail);

    efound= -1 ;
    myStrNameCpr(lEmail);

    if (efound ==-1) {
        printf("You cannot log in. Invalid email.\n");
        login();

    }

    printf("Enter ur email pw");
    scanf (" %[^\n]", &lPw);

    pfound = -1;
    passCheck(lPw, efound);

    if (pfound==-1){
        printf("You cannot log in. Invalid pw.\n");
    }
    if (efound != -1 && pfound==1 ){
        userActionSector();
    } else if (pfound==-1) {
        login();

    }
}

void myStrNameCpr(char userInputData[50]){

    int counter=0;
    int first = charCounting(userInputData);
        for (int i=0; i<globalIndex; i++){
            int second = charCounting(info[i].email);
                if ( first == second) {
                    for (int gcc = 0; gcc < first; gcc++) {
                        if ( info[i].email[gcc] != userInputData[gcc]) {
                            break;
                        } else {
                            counter++;
                        }
                    }
                }
            if (first==counter){
                 efound = i;
                 break;
            }
        }

}

int charCounting(char toCount[50]){
    int count=0;
    for (int gcc=0; gcc<50; gcc++){
        if (toCount[gcc] == '\0'){
            break;
        } else {
            count++;
        }
    }
    return count;
}

int gmailValidation(char tester[50]){

    int count = charCounting(tester)-1;
    if (tester[count]!='m'||tester[count-1]!='o'||tester[count-2]!='c'||tester[count-3]!='.'||tester[count-4]!='l'||tester[count-5]!='i'||
         tester[count-6]!='a'||tester[count-7]!='m'||tester[count-8]!='g'||tester[count-9]!='@') {
        return -1;
    }
    return 1;
}

void passCheck(char pass[50], int userIndex){

    int count=0;
    int first = charCounting(pass);
    int second = charCounting(info[userIndex].pw);
    if (first == second){
        for (int i=0; i<first; i++){
            if (pass[i]== info[userIndex].pw[i]){
                count++ ;
            } else {
                break;
            }
        }
    }
    if (count==first){
        pfound=1;
    }
}


void userActionSector(){

    int userAction = 0;
    printf("Welcome, you can play the game, %s\n", info[efound].name);
    printf("Press 1 to enter user action sector\n");
    printf("Press 2 to go home\n");
    printf("Press 3 to exit\n");
    scanf(" %d", &userAction);

    if (userAction==1){
        printf("This is uer action sector\n");
    } else if (userAction==2){
        login();
    } else if (userAction==3){
        recordingAllDataToAFile();
    } else{
        printf("Invalid option.\n");
        userActionSector();
    }
}


void recordingAllDataToAFile(){

    FILE *fptr ;
    fptr = fopen("19MiniPj", "w");
    if (fptr==NULL){
        printf("Error while opening the file, Plz try again");
    } else{
        info[globalIndex].id= globalIndex+1;
        for (int gcc=0; gcc<=globalIndex; gcc++){
            fprintf(fptr, " %d %s %d %s %s \n", info[gcc].id, info[gcc].name, info[gcc].age, info[gcc].email, info[gcc].pw);
        }
    }

    printf("Recording all data to '19MiniPj' complete\n");
    fclose(fptr);

}

void loadingDataFromFile(){

    FILE *fptr;
    fptr = fopen("19MiniPj", "r");
    if (fptr==NULL){
        printf("Error while loading data\n");
    } else {
        for (int gcc = 0; gcc < SIZE; gcc++) {
            fscanf(fptr, " %d %s %d %s %s \n", &info[gcc].id, &info[gcc].name, &info[gcc].age, &info[gcc].email, &info[gcc].pw);

            if (info[gcc].name[0]=='\0'){
                break;
            }
            globalIndex++;
        }
    }

    fclose(fptr);
}

void registration(){

    printf("This is register.\n");
    printf("Enter your name:");
    scanf(" %[^\n]", &info[globalIndex].name);

    printf("Enter your age:");
    scanf(" %d", &info[globalIndex].age);

    printf("Enter your email:");
    scanf(" %[^\n]", &info[globalIndex].email);

    if (gmailValidation(info[globalIndex].email)!= 1) {
        printf("Your gmail is not valid. It must end with @gmail.com\n");
        registration();
    }

    efound = -1;
    myStrNameCpr(info[globalIndex].email);
    if ( efound != -1){
        printf ("Use id already taken\n");
        registration();
    }
    printf("Enter your pw:");
    scanf(" %[^\n]", &info[globalIndex].pw);


    recordingAllDataToAFile();
    printf("Registration complete");


}