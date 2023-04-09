//
// Created by HUAWEI on 3/28/2023.
//

#ifndef C___ZOOM_ONLINE_BANK_H
#define C___ZOOM_ONLINE_BANK_H

#include "stdio.h"
#include "stdlib.h"
#define SIZE 1000

struct trans{
    char note[200];
};


struct data {
    unsigned int id;
    char name[50];
    char NRC[50];
    char email[50];
    char pw[50];
    char pOrb[10]; //personal or business
    char loan_status[1];
    unsigned int monthly_income;
    unsigned int loan_amount;
    float loan_rate;
    char acc_status[10];
    int acc_lvl;
    unsigned long long int phNumber;
    unsigned int cur_amount; //current amount
    char add[100];
    unsigned int trans_amt_limit_per_day;
    struct trans trc[100];
};

struct data db[SIZE];

//Global Variable Variation
int user = 0;
int gvalid = -1;
int emailExist = -1 ;
int two_char_array = -1;
int nrc_valid = -1;
int strongPass = -1;
int phone_valid = 1;
int name_exit = -1;
int phone_found = -1;

//Global array Variation
int space_array[30];
char int_to_char_array[10];


//For function declaration
void welcome();
void log_In();
void userSector();
void loadingAllDataFromFile();
void printingAllData();
int charCounting(char toCount[50]);
void myGmailValidation(char toValidate[50]);
void registration();
void emailExitChecking(char toCheck[50]);
void nameExitChecking(char name_to_check[50]);
void comp_two_char_arr(char first[50], char sec[50]);
void nrc_Validation (char NRC_to_check[50]);
void myStrongPassword (char pass[50]);
void phone_validation (unsigned long long int phone);
void myStringCopy (char first[50], char sec[50]);
void finding_phone_number (unsigned long long int to_find);
void transfer_money(int transfer, int receiver,unsigned int amount);
void space_counter();
void recording_allData_toFile();
void transaction_record(int transfer, int receiver, unsigned int amount, char who);
void integer_to_char(unsigned int value);

void welcome(){
    int option=0;
    printf("Hello, to our bank.\n");
    printf("Press 1 to LogIn.\nPress 2 to Register.\nPress 3 to Exit::::");
    scanf("%d",&option);

    if (option==1) {
        log_In();
    } else if (option==2){
        registration();
    } else if (option==3){
        recording_allData_toFile();
        exit(1);
    } else {
        welcome();
    }
}



void log_In() {
    char l_name[50];
    char l_email[50];
    char l_pw[50];

    emailExist = -1;
    name_exit  = -1;
    two_char_array = -1;
    printf("This is log in.\n");


    while ( emailExist == -1 ||  two_char_array == -1 || name_exit == -1){


        printf ("Please enter your name:");
        scanf (" %[^\n]", &l_name[0]);
        nameExitChecking(l_name);

        printf("Please enter your email:");
        scanf (" %[^\n]", &l_email[0]);
        emailExitChecking(l_email);

        if ((name_exit != emailExist) || name_exit==-1 || emailExist==-1){
            name_exit = -1;
            emailExist = -1;
            printf("There is no user name with this email. Please try again.\n");

        } else {

            printf("Please enter your password: ");
            scanf(" %[^\n]", &l_pw[0]);
            comp_two_char_arr(db[emailExist].pw, l_pw);

            if (emailExist == -1 || two_char_array == -1 || name_exit == -1) {

                emailExist = -1;
                two_char_array = -1;
                name_exit = -1;
                printf("Fail\n");
            }
        }
    }


        printf("Log IN succeed.");
        printf("Welcome Sir, %s\n", db[emailExist].name);
        printf("Your current amount is: %u\n",db[emailExist].cur_amount);
        userSector();
}

void userSector(){
    int user_option;
    unsigned long long int phone;
    unsigned int amount_to_transfer = 0;
    printf("This is user sector\n");
    printf("Press 1 to transfer Money:\nPress 2 to Withdraw:\nPress 3 to update your info:"
           "\nPress 4 to Cash in:\nPress 5 to Loan:\nPress 6 to view your history:\nPress 7 to return:\n ");
    scanf(" %d", &user_option);

    if(user_option == 1){
        printf("This is user transfer section:\n");
        phone_found = -1;
        while (phone_found == -1){
            printf("Enter receiver phone number:");
            scanf(" %llu",&phone);
            finding_phone_number(phone);
            if(phone_found == -1){
                printf("Phone does not belong to any user\n");
            }
        }
        printf("Are u sure to send for %s email: %s:\n",db[phone_found].name,db[phone_found].email);

        while (amount_to_transfer<db[emailExist].cur_amount){
            printf("Enter your amount to transfer:");
            scanf(" %u", &amount_to_transfer);
            if (db[name_exit].cur_amount-1000>=amount_to_transfer){
                printf("You can transfer.\n");
                break;
            } else {
                printf("Insufficient balance\n");
                amount_to_transfer = 0;
            }
        }

        two_char_array = -1;
        char tran_pass[50];
        int counter = 0;
        while (two_char_array == -1){
            printf("Enter your password to proceed transaction:");
            scanf(" %[^\n]",&tran_pass[0]);
            comp_two_char_arr(db[emailExist].pw, tran_pass);
            if (two_char_array == -1){
                printf("Your password was  incorrect!\n");
                counter ++;
            }
            if(counter == 3){
                printf("Too many attempt.\n");
                userSector();
            }
        }

        transfer_money(emailExist, phone_found, amount_to_transfer);
        recording_allData_toFile();
        userSector();


    } else if(user_option==7){
        welcome();
    } else {
        userSector();
    }
}


void transfer_money(int transfer, int receiver,unsigned int amount){

    printf("Loading to transfer........\n");
    db[transfer].cur_amount = db[transfer].cur_amount - amount;
    db[receiver].cur_amount = db[receiver].cur_amount + amount;

    transaction_record(transfer,receiver,amount,'t');
    transaction_record(transfer,receiver,amount,'r');

    printf("Transaction succeed!!\n");
}


void transaction_record(int transfer, int receiver, unsigned int amount, char who){

    int trans_name_counter = charCounting(db[transfer].name);
    int receive_name_counter = charCounting(db[receiver].name);
    integer_to_char(amount);
    int amount_counter = charCounting(int_to_char_array);


    char from[5] = {'F','r','o','m','-'};
    char to[4] = {'-','t','o','-'};
    int index_point = 0;
    if (who == 't'){
        for (int i=0; i<5; i++){
            db[transfer].trc[space_array[transfer]-15].note[i] = from[i];
            index_point++;
        }

        for (int j=0; j<trans_name_counter; j++){
            db[transfer].trc[space_array[transfer]-15].note[index_point] = db[transfer].name[j];
            index_point++;
        }

        for (int k = 0; k<4; k++){
            db[transfer].trc[space_array[transfer]-15].note[index_point] = to[k];
            index_point++;
        }

        for (int l = 0; l<receive_name_counter; l++){
            db[transfer].trc[space_array[transfer]-15].note[index_point] = db[receiver].name[l] ;
            index_point++;
        }

        db[transfer].trc[space_array[transfer]-15].note[index_point] = '-';
        index_point++;
        db[transfer].trc[space_array[transfer]-15].note[index_point] = '$';
        index_point++;
        for (int m=0 ; m<amount_counter; m++){
            db[transfer].trc[space_array[transfer]-15].note[index_point] = int_to_char_array[m];
            index_point++;
        }

        space_array[transfer]+=1;

    } else if (who == 'r'){
            char record[15] = {'-','R','e','c','e','i','v','e','d',' ','f','r','o','m','-'};
            index_point = 0;

            for (int i=0; i<15; i++){

                db[receiver].trc[space_array[receiver]-15].note[i] = record[i];
                index_point ++;
            }

            for (int j =0; j<trans_name_counter; j++){
                db[receiver].trc[space_array[receiver]-15].note[index_point] = db[transfer].name[j];
                index_point++;
            }
            db[receiver].trc[space_array[receiver]-15].note[index_point] = '-';
            index_point++;
            db[receiver].trc[space_array[receiver]-15].note[index_point] = '$';
            index_point++;


            for (int k=0; k<amount_counter; k++){
                db[receiver].trc[space_array[receiver]-15].note[index_point] = int_to_char_array[k];
                index_point++;
            }
            space_array[receiver]++;
    }
}
    //id Name NRC  email password pOrb loan_status monthly_income
//loan_amount loan_rate accountStatus account_level phNumber dob amount address trans_limit_per_day TransRC
void loadingAllDataFromFile() {
    FILE *fptr ;
    fptr = fopen("ncc_db.txt" ,"r");
    if (fptr== NULL){
        printf("Error while loading data from file");
    } else {
        for (int i=0;  i<SIZE; i++){

            fscanf(fptr, "%u%s%s%s%s%s%s%u%u%f%s%d%llu%u%s%u",&db[i].id, &db[i].name,&db[i].NRC, &db[i].email, &db[i].pw, &db[i].pOrb,
                   &db[i].loan_status, &db[i].monthly_income, &db[i].loan_amount, &db[i].loan_rate, &db[i].acc_status, &db[i].acc_lvl,&db[i].phNumber,
                   &db[i].cur_amount, &db[i].add, &db[i].trans_amt_limit_per_day);


            for (int j=0; j<space_array[i]-15; j++){

                fscanf(fptr, "%s",&db[i].trc[j].note );

            }
            if(db[i].email[0] == '\0'){
                break;
            }

            user++;
        }

    }
    fclose(fptr);

}


void space_counter(){
    FILE *fptr;
    fptr = fopen("ncc_db.txt", "r");
    if (fptr == NULL){
        printf("File opening error at space_counter function.\n");
    } else {
        char c = fgetc(fptr);
        int index = 0;
        while (!feof(fptr)){
            if (c != '\n'){
                if (c == ' '){
                    space_array[index]+=1;
                }
                c = fgetc(fptr);
            } else {
                index++;
                c = fgetc(fptr);
            }

        }

        for (int iii = 0; iii <30 ; iii++) {

            printf(" %d", space_array[iii]);
        }

        printf("\n");

    }
    fclose(fptr);
}

void printingAllData(){
    for (int i=0; i<user; i++){
        printf("%u-%s-%s-%s-%s-%s-%s-%u-%u-%f-%s-%d-+95%llu-%u-%s-%u",db[i].id, db[i].name,db[i].NRC, db[i].email, db[i].pw, db[i].pOrb,
               db[i].loan_status, db[i].monthly_income, db[i].loan_amount, db[i].loan_rate, db[i].acc_status, db[i].acc_lvl,db[i].phNumber,
               db[i].cur_amount, db[i].add, db[i].trans_amt_limit_per_day);

        for (int j=0; j<space_array[i]-15; j++){
            printf("-%s",db[i].trc[j].note);
        }
        printf("\n");
    }

}

void recording_allData_toFile(){
    FILE *fptr = fopen("ncc_db.txt", "w");
    if (fptr == NULL){
        printf("Cannot open file to record:\n");
    } else{
        for (int i=0; i<user; i++) {
            fprintf(fptr,"%u%c%s%c%s%c%s%c%s%c%s%c%s%c%u%c%u%c%f%c%s%c%d%c%llu%c%u%c%s%c%u",db[i].id, ' ',db[i].name,' ',db[i].NRC, ' ',db[i].email, ' ',db[i].pw, ' ',db[i].pOrb,' ',
                    db[i].loan_status, ' ',db[i].monthly_income, ' ',db[i].loan_amount,' ', db[i].loan_rate, ' ',db[i].acc_status, ' ',db[i].acc_lvl,' ',db[i].phNumber,' ',
                    db[i].cur_amount, ' ',db[i].add, ' ',db[i].trans_amt_limit_per_day);

            for (int j=0; j<space_array[i]-15; j++){
                fprintf(fptr, " %s",db[i].trc[j].note);
            }

            fprintf(fptr, "%c",'\n');
        }
    }

    fclose(fptr);
}

void registration(){
    char reEmail[50];
    char reName[50];
    char re_NRC[50];
    char re_pass[50];
    unsigned long long int re_phone;

    printf("This is NCC bank User Registration.\n");
    printf("Enter your email");
    scanf( " %[^\n]",&reEmail);
    gvalid= -1;
    myGmailValidation(reEmail);
    if (gvalid != -1){

        emailExist= -1 ;
        emailExitChecking(reEmail);
        if (emailExist == -1){
            printf("Email registration succeed.\n");
            printf ("Please Enter your name");
            scanf (" %[^\n]",&reName[0]);
            nrc_valid = -1;

            while (nrc_valid == -1){
                printf("Enter your NRC:");
                scanf(" %[^\n]", &re_NRC);
                nrc_Validation(re_NRC);
                if (nrc_valid == -1 ){
                    printf("Your nrc format was not valid.\n");
                }
            }

            printf("Your NRC format is valid.\n");
            strongPass=-1;
            while (strongPass == -1){
                printf("Enter your password:");
                scanf( " %[^\n]", &re_pass);
                myStrongPassword(re_pass);
                if (strongPass == -1){
                    printf("Your Password Format too weak and Try Again!\n");
                }
            }

            printf("Your password format was valid and save.\n");
            phone_valid = -1;

            while (phone_valid == -1){
                printf("Enter your phone number:");
                scanf (" %llu", &re_phone);

                phone_validation(re_phone);

            }
            db[user].phNumber = re_phone;
            printf("Ph number registration succeed!\n");
             printf("Enter your amount");
             scanf (" %u", &db[user].cur_amount);
             printf("Enter your address:");
             scanf (" %[^\n]", &db[user].add);
             printf("Enter your note:");
             scanf (" %[^\n]",  &db[user].trc[0].note[0]);

            myStringCopy( db[user].email, reEmail);
            myStringCopy(db[user].name, reName);
            myStringCopy(db[user].NRC, re_NRC);
            myStringCopy(db[user].pw, re_pass);
            myStringCopy(db[user].pOrb, db[2].pOrb);
            myStringCopy( db[user].loan_status, db[2].loan_status);
            myStringCopy(db[user].acc_status, db[2].acc_status);
            db[user].monthly_income = db[2].monthly_income;
            db[user].loan_amount = db[2].loan_amount;
            db[user].loan_rate = db[2].loan_rate;
            db[user].acc_lvl = db[2].acc_lvl;
            db[user].trans_amt_limit_per_day = db[2].trans_amt_limit_per_day;
            db[user].id = user+1 ;

            user++;
            printf ("Registration succeed!.\n");
            recording_allData_toFile();
            welcome();

        } else {
            printf ("User email already taken at user %d.\n",emailExist+1);
            registration();
        }


    } else {
        printf("Your gmail format is not valid.\n");
        registration();
    }

}


int charCounting(char toCount[50]){
    int charCount = 0;

    for (int i = 0; i <50 ; i++) {
        if (toCount[i] == '\0'){
            break;
        } else {
            charCount++;
        }
    }
    return charCount;
}

void myGmailValidation(char toValidate[50]){
    char form[10]={'@','g','m','a','i','l','.','c','o','m'};
    int count=0;
    int endPoint = charCounting(toValidate);
    for (int i = 0; i <endPoint ; i++) {
        if (toValidate[i] == '@' || toValidate[i] == ' ' ){
            break;
        } else{
            count++;
        }
    }

    int validCount=0;

    for (int i=0; i < 10 ; i++){
        if (toValidate[count] != form[i]){
            break;
        } else{
            validCount++;
            count++;
        }
    }

    if (validCount==10){
        gvalid=1;
    }
}

void emailExitChecking(char toCheck[50]){

    int toCheckCount = charCounting(toCheck);
    int sameCounting =0 ;

    for (int i=0; i<user; i++){
        int dbEmailCount = charCounting(db[i].email);

        sameCounting = 0;
        if (dbEmailCount == toCheckCount){
            for ( int j=0; j<toCheckCount; j++){
                if (toCheck[j] != db[i].email[j]){
                    break;
                } else {
                    sameCounting++;
                }
            }
        }

        if (sameCounting== toCheckCount){
            emailExist = i;
            break;

        }
    }

}


void nameExitChecking(char name_to_check[50]){

    int name_count = charCounting(name_to_check);
    int same_Counting = 0;
    for (int i=0; i<user; i++){
        int db_name_count = charCounting(db[i].name);
        if (name_count = db_name_count){
            for (int j=0; j<name_count; j++){
                if (name_to_check[j] == db[i].name[j]){
                    same_Counting++;
                } else {
                    break;
                }
            }
        }
        if (same_Counting == name_count){

            name_exit = i;
            break;
        }

    }

}


struct nrc_region {
    char region[10];
};
// ) = 41
struct nrc_region nrc[4];

void nrc_Validation(char NRC_to_check[50]){

    int nrc_counter = charCounting(NRC_to_check);
    int nrc_char_count = 0;
    for (register int i=0; i<nrc_counter; i++){
        if (NRC_to_check[i]  == ')' ){
            break;
        } else{

            nrc_char_count++;

        }

    }

    for (int i=0; i<4 ; i++){

        two_char_array = -1;
        comp_two_char_arr(NRC_to_check, db[i].NRC);
        if (two_char_array == 1){
            nrc_valid = 1;
            break;
        }
    }

}




void comp_two_char_arr(char first[50], char sec[50]){

    int first_counter = charCounting(first);
    int sec_counter = charCounting(sec);
    int same_counter = 0;

    if (first_counter == sec_counter){
        for ( register int i = 0; i< first_counter; i++){
            if (first[i] != sec[i]){
                break;
            }
                same_counter++;

        }

        if (same_counter == first_counter){

            two_char_array = 1;
        }

    }


}


void myStrongPassword (char pass[50]){

    int i=0;
    int specialChar = 0;
    int smallChar = 0;
    int capChar = 0;
    int numChar = 0;
    int passCounter = charCounting(pass);

    while (strongPass == -1){

        if (passCounter < 8){
            strongPass =-1;
            break;
        }
        if ( i == passCounter){
            break;
        }
        if ( pass[i] >=33 && pass[i] <=42){

            specialChar++;
        } else if ( pass[i] >= 48 && pass[i] <= 57){

            numChar++;
        } else if ( pass[i] >= 64 && pass[i] <= 90){

            capChar++;
        } else if (pass[i] >= 97 && pass[i] <= 122) {

            smallChar++;
        }


        i++;

        if (specialChar >0 && numChar >0 && capChar > 0 && smallChar > 0){
            strongPass = 1 ;
        }
    }
}


void phone_validation (unsigned long long int phone){

    int phone_counter = 0;
    for (int i=0; i<user; i++){
        if (phone == db[i].phNumber){
            break;
        } else {
            phone_counter++;
        }
    }

    if(phone_counter == user){
        phone_valid = 1;
    } else {
        printf("Your ph number already taken.\n");
        phone_valid = -1;
    }
}


void myStringCopy (char first[50], char sec[50]){

    int secCount = charCounting(sec);

//    for (int i=0; i < 50; i++){
//        first[i] = '\0';
//    }

    for ( int j=0; j<secCount; j++){
        first[j] = sec[j] ;
    }
}


void finding_phone_number (unsigned long long int to_find){

    for(int i=0; i<user; i++){
        if(to_find == db[i].phNumber){
            phone_found = i;
            break;
        }
    }
}


void integer_to_char(unsigned int value) {

    FILE *fptr = fopen("int_to_char.txt", "w");
    if (fptr == NULL){
        printf("File opening error");
    } else {
        fprintf(fptr, "%u", value);
    }

    fclose(fptr);

    FILE *fptr2 = fopen ("int_to_char.txt", "r");
    if (fptr2 == NULL){
        printf("File opening error");
    } else {
        fscanf(fptr2, "%s", &int_to_char_array[0]);
    }

    fclose(fptr2);

}



#endif //C___ZOOM_ONLINE_BANK_H
