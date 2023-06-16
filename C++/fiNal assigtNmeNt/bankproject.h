//
// Created by zl_shit_h on 06/06/23.
//

#ifndef C___BANKPROJECT_H
#define C___BANKPROJECT_H

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
    unsigned long long int phNumber;
    unsigned int cur_amount;
    char add[100];
    unsigned int trans_limit_per_day;
    struct trans trc[100];

};

struct data db;
struct node* root = NULL;


//function declaration
struct node* insertion(struct data db, struct node* root);

void welcome();
int char_counting(char to_count[50]);
int gmail_validation(char G_valid[50]);
int strong_password(char to_check[50]);
int compare_two_char_arr(char first[50], char sec[50]);
void my_string_copy(char org[50], char to_get_copied[50]);
void registration();
struct data loading_data_from_file_to_AVL();

//global variable declaration
int g_valid = -1;

void welcome(){
    int option;
    printf("Welcome to our bank\n");
    printf("Press 1 to register.\nPress 2 to Log in.\nPress 3 to exit.");
    scanf("%d",&option);

    if (option == 1){
        registration();
    } else if (option == 2){
        printf("Log in");
    } else if (option == 3){
        exit(1);
    } else{
        welcome();
    }
}


void registration() {
    unsigned int id;
    char r_email[50];
    char r_name[50];
    char r_pw[50];
    char r_nrc[50];
    char add[50];
    int pass_checker = -1;
    unsigned long long int ph_no;
    unsigned int cur_amount;


    printf("\nThis is REGISTRATION SECTION!\n");
    printf("Enter id :");
    scanf("%u",&id);
//    printf("Enter your e-mail: ");
//    scanf(" %[^\n]",&r_email[0]);
//    g_valid =-1;
//    g_valid = gmail_validation(r_email);
//    while (g_valid == -1){
//
//        printf("E-mail format is not valid. Plz try again!\n");
//        registration();
//
//    }
//
//    printf("Email registration succeed.\n");
//    printf("Enter your name: ");
//    scanf(" %[^\n]", &r_name[0]);
//    pass_checker = -1;
//    while (pass_checker == -1){
//        printf("Sir: %s, Please enter your password : ",r_name);
//        scanf(" %[^\n]",r_pw);
//        pass_checker = strong_password(r_pw);
//        if (pass_checker == -1){
//            printf("Password was too weak!!");
//        }
//    }
//
//    printf("Pass\n");
//
//    printf("Enter your NRC:");
//    scanf(" %[^\n]", &r_nrc[0]);
//    printf("Your NRC: %s\n", r_nrc);
//    printf("Enter your phone number:");
//    scanf(" %llu",&ph_no);
//    printf("%llu\n", ph_no);
//    printf("Enter your current amount:");
//    scanf("%u",&cur_amount);
//    printf("%u\n", cur_amount);
//    printf("Enter your address:");
//    scanf(" %[^\n]", &add[0]);
//    printf("%s\n",add);
//    my_string_copy(r_email, db.email);
//    my_string_copy(r_name, db.name);
//    my_string_copy(r_pw, db.password);
//    my_string_copy(r_nrc, db.NRC);
//    my_string_copy(add, db.add);
//    db.phNumber = ph_no;
//    db.cur_amount = cur_amount;

    db.id = id;

    root = insertion(db, root);

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

int strong_password(char to_check[50]){
    int small = 0;
    int capital = 0;
    int special = 0;
    int digit = 0;
    int counter = char_counting(to_check);
    if (counter <=6 ){
        return -1;
    }
    for (int i=0; i<counter; i++){

        if (to_check[i] >=33 && to_check[i] <= 47){
            special++;

        } else if (to_check[i] >=48 && to_check[i] <= 57){
            digit++;

        } else if (to_check[i] >= 65 && to_check[i] <= 90){
            capital++;

        } else if ( to_check[i] >= 97 && to_check[i] <= 122){
            small++;

        } else {
            return -1;

        }

    }

    if (special > 0 && digit > 0 && capital > 0 && small > 0 ){
        return 1;

    } else {
        return -1;
    }

}


int compare_two_char_arr(char first[50], char sec[50]){

    int first_counter = char_counting(first);
    int sec_counter = char_counting(sec);
    int mutual_counter =0;
    if (first_counter != sec_counter){
        return -1;
    } else {

        for (int i=0; i<first_counter; i++){
            if(first[i] != sec[i]){
                return -1;
            }
            mutual_counter++;
        }

        if (mutual_counter != first_counter){
            return -1;

        } else{
            return 1;

        }
    }

}


void nrc_validation(char nrc_to_check[50]){
    int counter = char_counting(nrc_to_check);
    if (counter <= 15){

    } else {

        for (int i=0; i<counter; i++){


        }
    }
}


void my_string_copy(char org[50], char to_get_copied[50]){
    int i=0;
    while (org[i] != '\0'){
        to_get_copied[i] = org[i];
        i++;

    }
}

struct data loading_data_from_file_to_AVL(){

    FILE *fptr = fopen("data_base","r");
    if (fptr ==NULL){
        printf("Error at file opening!");
    } else {

        //Scanning data from file until end of file
        while (!feof(fptr)){
//            fscanf(fptr, "%u%s%s%s%s%s%u%u%s%d%llu%u%s%u%s",&db.id, &db.name[0], &db.email[0], &db.password, &db.NRC, &db.pOrb, &db.monthly_income,
//                   &db.loan_amount, &db.acc_status, &db.acc_lvl, &db.phNumber, &db.cur_amount, &db.add, &db.trans_limit_per_day,
//                   &db.trc[0].note);


            fscanf(fptr, "%u",&db.id);

            //Inserting db structure to AVL Tree
            root = insertion(db, root);
        }

//        fscanf(fptr, "%s", &db.name[0]);

    }

    fclose(fptr);

    return db;
}
#endif //C___BANKPROJECT_H
