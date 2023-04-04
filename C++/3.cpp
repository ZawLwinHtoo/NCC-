#include "stdio.h"
#include "stdlib.h"
int db[100] ;
int main(){
    int key=10;
    int age=0 ;
    int option;
    int userId;
    int flag=0;
    int i=0;
    int userId2;
    int flag2=0;
    int dbIndex=0;
    int dbIndex2=0;
    int dbMoney[100];
    int moneyOption;

    while(key<=10) {
        printf("Welcome to our game.\n");
        printf("Please enter your age:");
        scanf("%d",&age);
        if (age > 17) {

                printf("You can play our game.\n");
            while(true) {
                printf("Press 1 to register.\nPress 2 to log in.\nPress 3 to return.\nPress 4 to exit.");
                scanf("%d", &option);


                    while(option==1) {
                        if (option == 1) {
                            printf("This is register.\n");
                            printf("Enter your id:");
                            scanf("%d", &userId);
                            for (i = 0; i < 100; i++) {
                                if (db[i] == userId) {
                                    flag = 1;
                                }
                            }

                            if (flag == 1) {
                                printf("User id is already taken.\nTry again!\n");
                                flag=0;
                            } else {
                                printf("Plz confirm your id again:");
                                scanf("%d", &userId2);
                                if (userId == userId2) {
                                    db[dbIndex]=userId;
                                    dbIndex++;
                                    printf("Registration succeed.\n");
                                    break;
                                } else {
                                    printf("Incorrect Id.\nTry again\n");
                                }
                            }
                        }
                    }
                    if (option == 2) {
                        printf("This is log in.\n");
                        printf("Plz enter your ID:");
                        scanf("%d", &userId);
 
                        for (i = 0; i <= 100; i++) {
                            if (db[i] == userId) {
                                flag = 1;
                            }
                        }

                        if (flag == 1) {
                            printf("You can play game.\n");
                            flag=0;

                        } else {
                            printf("Your id is not valid.\n");

                        }
                    } else if (option == 3) {
                        break;
                    } else if (option == 4) {
                        exit(1);
                    } else if (option>4){
                        printf("Invalid option.\n");
                    }

            }
        } else {
            printf("You cannot play our game.\nTry again!\n");
        }
    }
    return 0;
}