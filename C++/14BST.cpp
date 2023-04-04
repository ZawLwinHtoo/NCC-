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

    struct node* newNode= (struct node*)malloc(sizeof (struct node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* InsertNode(struct node* root, int key){

    if (root == NULL){
        return createNode(key);
    }

    if (key < root->data){
        root->left = InsertNode(root->left, key);
    }else {
        root->right = InsertNode(root->right, key);
    }
    return root ;
}
int main(){
    struct node* root = NULL;
    root = InsertNode(root, 10);
    root = InsertNode(root, 15);
    root = InsertNode(root, 5);
    root = InsertNode(root, 1);
    root = InsertNode(root, 20);
    return 0 ;
}