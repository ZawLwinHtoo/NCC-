//
// Created by zl_shit_h on 27/05/23.
//

#include "stdio.h"
#include "stdlib.h"


char int_to_char_array[10];
struct node{
    int data;
    struct node* right;
    struct node* left;

};

struct node* root = NULL;

void integer_to_char(unsigned int value) {

    FILE *fptr = fopen("1.1.txt", "w");
    if (fptr == NULL){
        printf("File opening error");
    } else {
        fprintf(fptr, "%d", value);
    }

    fclose(fptr);

    FILE *fptr2 = fopen ("1.1.txt", "r");
    if (fptr2 == NULL){
        printf("File opening error");
    } else {
        fscanf(fptr2, "%s", &int_to_char_array[0]);
    }

    fclose(fptr2);

}


struct node* create_node(int data){
    struct node* new_node = (struct node*) malloc(sizeof (struct node));
    if (new_node == NULL){
        printf("Memory cant be allocated");
        return NULL;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}


struct node* insert_new_node(struct node* root, int data){
    if (root == NULL){
        return create_node(data);
    }

    if (data > root->data){
        root->right = insert_new_node(root->right, data);
    } else {
        root->left = insert_new_node(root->left, data);
    }

    return root;
}



void recursion_in_tree(FILE* fptr, struct node* root){
    if (root != NULL){
        recursion_in_tree(fptr, root->left);
        integer_to_char(root->data);

        fprintf(fptr, "%c%c",int_to_char_array[0],'\n');
        recursion_in_tree(fptr, root->right);
    }

}

void record_to_file(struct node* root){
    FILE *fptr = fopen("1.txt", "w");
    recursion_in_tree(fptr, root);
    fclose(fptr);

}



int main(){

    root = insert_new_node(root, 5);
    root = insert_new_node(root, 7);
    root = insert_new_node(root, 2);
    record_to_file(root);
    return 0;
}



