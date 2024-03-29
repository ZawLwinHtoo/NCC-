//
// Created by zl_shit_h on 31/05/23.
//

#ifndef C___AVL_FOR_BANK_H
#define C___AVL_FOR_BANK_H

#include "bankproject.h"

//struct node {
//    struct data* db;
//    struct node* left;
//    struct node* right;
//    int height;
//};

//Global Var


//Function Declaration

struct node* create_node(struct data* DB);
int height (struct node* root);
int balance_factor(struct node* root);
struct node* rotate_right(struct node* root);
struct node* rotate_left (struct node* root);
struct node* insertion(struct data* db, struct node* root);
void Inorder_Traversal (struct node* root);
void print_data(struct node* root);
void inorder_Traversal_record (struct node* root, FILE *fptr);
void open(struct node* root);


struct node* create_node(struct data* DB){
    int i = 0;
    struct node* new_node = (struct node*) malloc(sizeof (struct node));
    new_node->db = (struct data*) malloc(sizeof (struct data));


    if (new_node == NULL){
        printf("Memory cannot be allocated!");
    } else {
        new_node->db->id = DB->id;
        new_node->db->monthly_income = DB->monthly_income;
        new_node->db->loan_amount = DB->loan_amount;
        new_node->db->acc_lvl = DB->acc_lvl;
        new_node->db->phNumber = DB->phNumber;
        new_node->db->cur_amount = DB->cur_amount;
        new_node->db->trans_limit_per_day = DB->trans_limit_per_day;
        while ( DB->email[i] != '\0' || DB->name[i] != '\0' || DB->password[i] != '\0' || DB->NRC[i] != '\0'){

            new_node->db->email[i] = DB->email[i];
            new_node->db->name[i] = DB->name[i];
            new_node->db->password[i] = DB->password[i];
            new_node->db->NRC[i] = DB->NRC[i];

            i++;
        }


        i = 0;
        while (DB->pOrb[i] != '\0'){

            new_node->db->pOrb[i] = DB->pOrb[i];
            i++;
        }

        i = 0;
        while (DB->acc_status[i] != '\0'){
            new_node->db->acc_status[i] = DB->acc_status[i];
            i++;
        }

        i = 0;
        while (DB->add[i] != '\0'){

            new_node->db->add[i] = DB->add[i];
            i++;
        }

        // TRC RECORD
        i=0;
        while (DB->trc[0].note[i] != '\0'){

            new_node->db->trc[0].note[i] = DB->trc[0].note[i];
            i++;
        }


    }
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;

}


struct node* rotate_right(struct node* root){

    struct node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;


    left_child->height = height(left_child);
    root->height = height(root);

    return left_child;
}


struct node* rotate_left (struct node* root){

    struct node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;

    root->height = height(root);
    right_child->height = height(right_child);

    return right_child;
}

int balance_factor(struct node* root){
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->height;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->height;
    return lh - rh;
}

int height (struct node* root){
    int lh, rh = 0;
    if (root == NULL){
        return 0;

    }
    if (root->left == NULL){
         lh = 0;

    } else {
        lh = 1 + root->left->height;

    }

    if (root->right == NULL) {
        rh = 0;
    } else {
        rh = 1 + root->right->height;

    }

    if (lh>rh){
        return lh;
    } else {
        return rh;
    }
}


struct node* insertion(struct data* db, struct node* root){
    if (root == NULL){
        struct node* new_node = create_node(db);

        if(new_node == NULL){
            return NULL;
        }
        root = new_node;

    } else if(db->id > root->db->id){

        root->right = insertion(db, root->right);

        if (balance_factor(root) == -2){
            if (db->id > root->right->db->id){
                root = rotate_left(root);
            } else {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    } else {
        root->left = insertion(db, root->left);

        if (balance_factor(root) == 2){
            if (db->id < root->left->db->id){
                root = rotate_right(root);

            } else {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    root->height = height(root);
    return root;
}



void print_data(struct node* root){
    printf("%u-%s-%s-%s-%s-%s-%u-%u-%s-%d-%llu-%u-%s-%u-%s %c",root->db->id,root->db->name, root->db->email, root->db->password, root->db->NRC, root->db->pOrb,
           root->db->monthly_income, root->db->loan_amount, root->db->acc_status, root->db->acc_lvl, root->db->phNumber, root->db->cur_amount, root->db->add, root->db->trans_limit_per_day
            ,root->db->trc[0].note,'\n');
}




void record_data(struct node* root, FILE *fptr){
    fprintf(fptr,"%u %s %s %s %s %s %u %u %s %d %llu %u %s %u %s %c",root->db->id,root->db->name, root->db->email, root->db->password, root->db->NRC, root->db->pOrb,
            root->db->monthly_income, root->db->loan_amount, root->db->acc_status, root->db->acc_lvl, root->db->phNumber, root->db->cur_amount, root->db->add, root->db->trans_limit_per_day
            ,root->db->trc[0].note,'\n');


}

void Inorder_Traversal (struct node* root){
    if ( root == NULL){
        return;
    }
    Inorder_Traversal(root->left);
    print_data(root);
    Inorder_Traversal(root->right);
}

void open(struct node* root){
    FILE *fptr = fopen("data_base", "w");
    inorder_Traversal_record(root, fptr);
    fclose(fptr);
}

void inorder_Traversal_record (struct node* root, FILE *fptr){
    if ( root == NULL){
        return;
    }
    inorder_Traversal_record(root->left, fptr);
    record_data(root,fptr);
    inorder_Traversal_record(root->right, fptr);
}



#endif //C___AVL_FOR_BANK_H




