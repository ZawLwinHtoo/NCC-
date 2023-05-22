//
// Created by zl_shit_h on 19/05/23.
//
#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* root = NULL;

struct node* create_node(int data){

    struct node* new_node = (struct node*)malloc(sizeof (struct node));
    if (new_node == NULL){
        printf("Memory cant bee allocated");
    }


}