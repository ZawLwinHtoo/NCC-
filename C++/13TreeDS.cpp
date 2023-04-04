//
// Created by HUAWEI on 12/24/2022.
//
#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int key){

    struct node* newNode = (struct node*) malloc(sizeof (struct node));
    newNode -> data = key;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return  newNode;

}

struct node* InsertRight (struct node* root , int key){

    root -> right = createNode(key);
    return  root-> right ;
}

struct node* InsertLeft(struct node* root, int key){

    root->left = createNode(key);
    return root->left;
}
int main(){

    struct node* root = createNode(100);
    InsertRight(root, 20);
    InsertLeft(root, 10);
    InsertRight(root->right, 40);
    InsertLeft(root->right, 60);
    InsertRight(root->left, 80);
    InsertLeft(root->left, 90);
    return 0;
}