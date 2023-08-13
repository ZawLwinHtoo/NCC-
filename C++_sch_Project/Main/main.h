//
// Created by zl_shit_h on 04/08/23.
//

#ifndef C___SCH_PROJECT_MAIN_H
#define C___SCH_PROJECT_MAIN_H


#include <iostream>
#include "string"
#include "cstring"
#define SIZE 50
#include "SNAKE/main_for_snake.h"
#include "CONNECT_4/main_for_connect_4.h"
#include "Tic_Tac_Toe/main_for_tic_tac_toe.h"
using namespace std;


struct data{
    string name;
    string email;
    string password;
    int score_point;
};

struct data db[SIZE];

//Function Declaration
void welcome();
void registration();
int gmail_validation(string to_Valid);
int strong_pass_check(string pass);
void log_in();
void user_sector();

void welcome(){
    int option;
    cout<<"Welcome to our program!!\n";
    cout<<"Press 1 to Register:\nPress 2 to Log in:\nPress 3 to Exit:";
    cin>>option;

    if (option == 1 ){
        registration();
    } else if (option == 2 ){
        log_in();
    } else if(option == 3 ){
        ::exit(1);
    } else {
        cout<<"Enter only in the given range!";
        welcome();
    }
}


void registration(){
//    char r_email[50];
    string r_email;
    string r_name;
    string r_pw;
    int email_exit = -1;
    int strong_pass = -1;

    cout<<"Enter your email :";
//    cin.getline(r_email,50);
    getline(cin,r_email);
    email_exit = gmail_validation(r_email);
    if (email_exit != -1){
        cout<<"Email registration succeed.\n";
        cout<<"Enter your user_name :";
        getline(cin,r_name);
//            cin>>r_name;
        cout<<"Enter your password :";
        getline(cin,r_pw);
//            cin>>r_pw;
        strong_pass = strong_pass_check(r_pw);
        if (strong_pass != -1){
            cout<<"Registration Succeed!";
            db[0].name = r_name;
            db[0].password = r_pw;
            db[0].email = r_email;
            welcome();
        } else {
            cout<<"Password is too weak!!! Try again:\n";
            registration();
        }
    } else {
        cout<<"Email format invalid. Try again\n";
        registration();
    }


}

void log_in(){
    string l_name;
    string l_pw;

    cout<<"This is login sector."<<endl;
    cout<<"Enter your user name :";
    cin>>l_name;
    cout<<"Enter your password :";
    cin>>l_pw;
    cout<<"\nLog in succeed!";
    cout<<"Welcome "<<l_name<<" !!!\n";
    user_sector();
}

void user_sector(){
    int option;

    cout << "***************" << endl;
    cout << "***************" << endl;
    cout << "*****ARCADE GAME*******" << endl;
    cout << "***************" << endl;
    cout << "***************" << endl <<endl;

    cout << "***************" << endl;
    cout << "Welcome Gamers!" << endl;
    cout << "Here in the \"ARCADE GAME\" we have plenty of games to play" << endl <<endl;

    do {
        cout << "***************" << endl;
        cout << "Available Games:" <<endl << endl;
        cout << "1.Hangman Game"<<endl;
        cout << "2.Tic-Tac-Toe"<<endl;
        cout << "3.Tetris Game"<<endl;
        cout << "4.Snake Game"<<endl;
        cout << "5.Connect-4 Game"<<endl <<endl;
        cout << "***************" << endl;

        cout << "Choose a game(1-5): ";
        cin>>option;
        if (option ==1){

        } else if (option ==2){
            Main_Tic_Tac_Toe();
        } else if (option == 3){

        } else if (option == 4){
            Main_Snake();
        } else if (option == 5){
            Main_Connect_4();
        } else {
            cout<<"\n\n*******Invalid option!*******!!"<<endl;
            cout<<"**********Please choose within the given options*******\n"<<endl;
        }
        cout << endl << endl;

    } while (true);



}


int gmail_validation(string to_Valid){
    int flag;
    string to_check;
    string Available[3] = {"@gmail.com","@yahoo.com","@email.com"};
    for (int i=0; i<to_Valid.length(); i++){
        if (to_Valid[i] == ' '){
            return -1;
        }

        if ( to_Valid[i] == '@'){
            flag = i;
            break;
        }

    }

    for (int i = flag; i<to_Valid.length(); i++){
        to_check+=to_Valid[i];
    }

    for (int i=0 ;i<3; i++){
        if (to_check == Available[i]){
            return 1;
        }
    }
    return -1;
}

int strong_pass_check(string pass){

    int i=0;
    int specialChar = 0;
    int smallChar = 0;
    int capChar = 0;
    int numChar = 0;

    while (true){

        if (pass.length() < 8){
            return -1;
        }
        if ( i == pass.length()){
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
            return 1;
        }
    }
    return 0;

}


#endif //C___SCH_PROJECT_MAIN_H
