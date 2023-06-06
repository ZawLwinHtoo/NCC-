//
// Created by zl_shit_h on 30/05/23.
//

#ifndef C___BANKASSIGNMENT_H
#define C___BANKASSIGNMENT_H


#include "stdlib.h"
#include "stdlib.h"
#include "stdbool.h"
#include "AVL_for_bank.h"
//structures declaration
struct trans{
    char note[200];
};
struct data{
    unsigned int id;
    char name[50];
    char email[50];
    char password[50];
    char NRC[50];
    char pOrb[10];
    unsigned int monthly_income;
    unsigned int loan_amount;
    char acc_status[10];
    int acc_lvl;
    unsigned int ph_number;
    unsigned int cur_amount;
    char add[100];
    unsigned int trans_limit_per_day;
    struct trans trc[100];

};


//function declaration
void welcome();
int char_counting(char to_count[50]);
int gmail_validation(char G_valid[50]);


//global variable declaration
int g_valid = -1;

void welcome(){
    int option;
    printf("Welcome to our bank\n");
    printf("Press 1 to register.\nPress 2 to Log in.\nPress 3 to exit.");
    scanf("%d",&option);

    if (option == 1){
        printf("Register");
    } else if (option == 2){
        printf("Log in");
    } else if (option == 3){
        exit(1);
    } else{
        welcome();
    }
}


void registration() {

    char r_email[50];
    char r_name[50];
    printf("\This is REGISTRATION SECTION!\n");
    printf("Enter your e-mail: ");
    scanf(" %[^\n]",&r_email[0]);
    g_valid =-1;
    g_valid = gmail_validation(r_email);
    while (g_valid == -1){

        printf("E-mail format is not valid. Plz try again!\n");
        registration();

    }

    printf("Email registration succeed.\n");
    printf("Enter your name: ");
    scanf(" %[^\n]", &r_name[0]);
    printf("%s",r_name);

//    printf("Enter your ")
}

int gmail_validation(char G_valid[50]){
    char std_form[10] = {'@','g','m','a','i','l','.','c','o','m'};
    int g_valid_counter = char_counting(G_valid);
    int j =0;
    for (int i =0; i<g_valid_counter-10; i++){
        if ( G_valid[i] == ' '){
            return -1;
        }
    }
    for (int i = g_valid_counter-10; i<g_valid_counter; i++){
        if (G_valid[i] == std_form[j]){
            j++;
        } else {
            break;
        }
    }

    if (j == 10){
        return 1;
    } else{
        return -1;
    }

}


int char_counting(char to_count[50]){
    int counter = 0;
    while (true) {
        if (to_count[counter] == '\0' || counter>50){

            break;
        } else {

            counter++;
        }
    }

    return counter;

}


void random_num(){


}


#endif //C___BANKASSIGNMENT_H
