// Recording data from AVL tree to file
// and load back



#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* root = NULL;


//global variable declaration
char  int_to_char_array[10];

//fun declaration
struct node* create_node(int data);
struct node* rotate_left(struct node* root);
struct node* rotate_right (struct node* root);
int height(struct node* root);
int balance_factor(struct node* root);
struct node* insert (struct node* root, int data);
void recursion_in_tree(FILE* fptr, struct node* root);
void record_to_file(struct node* root);
void integer_to_char(unsigned int value);
struct node* read_from_file();


int main(){
    int option;
    root = read_from_file();
    while (true){
        printf("_______AVL TREE________\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n7. Exit\n");
        scanf("%d",&option);
        if (option == 1){
            int data;
            printf("Enter data: ");
            scanf("%d",&data);
            root = insert(root, data);
            record_to_file(root);
        }
    }
    record_to_file(root);

    return 0;
}


struct node* create_node(int data) {

    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory cant bee allocated");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;

}

struct node* rotate_left(struct node* root){
    struct node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;

    right_child->height = height(right_child);
    root->height = height(root);

    return right_child;

}


struct node* rotate_right (struct node* root){

    struct node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;

    left_child->height = height(left_child);
    root->height = height(root);

    return left_child;
}



int height(struct node* root){
    int lh,rh;

    if (root == NULL){
        return 0;
     }

    if (root->left == NULL){
        lh = 0;
    } else {
        lh = 1 + root->left->height;
    }

    if (root->right == NULL){
        rh = 0;
    } else {
        rh = 1 + root->right->height;
    }

    if (lh > rh){
        return lh;
    }
    return rh;
}


int balance_factor(struct node* root){
    int lh, rh ;
    if (root == NULL){
        return 0;
    }

    if (root->left == NULL){
        lh = 0;
    } else{
        lh = 1 + root->left->height;
    }

    if (root->right == NULL){
        rh = 0;
    } else{
        rh = 1 + root->right->height;
    }

    return lh - rh ;
}

struct node* insert (struct node* root, int data){
    if (root == NULL){
        struct node* new_node = create_node(data);

        if (new_node == NULL){

            return NULL;
        }
        root = new_node;
    } else if (data > root->data){
        root->right = insert(root->right, data);

        if (balance_factor(root) == -2){

            if (data > root->right->data){
                root = rotate_left(root);

            } else{
                root->right = rotate_right(root->right);
                root = rotate_left(root);

            }
        }//


    } else{
        root->left = insert(root->left, data);

        if (balance_factor(root) == 2){

            if (data < root->left->data){
                root = rotate_right(root);

            } else{
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }

    root->height = height(root);
    return root;

}


void recursion_in_tree(FILE* fptr, struct node* root){
    if (root != NULL){
        recursion_in_tree(fptr, root->left);
        //integer_to_char(root->data);

        fprintf(fptr, "%d%c",root->data,'\n');
        recursion_in_tree(fptr, root->right);
    }

}

void record_to_file(struct node* root){
    FILE *fptr = fopen("1.txt", "w");
    recursion_in_tree(fptr, root);
    fclose(fptr);

}

struct node* read_from_file(){
    int i;
    struct node* Root;
    FILE* fptr = fopen("1.txt", "r");
    if (fptr == NULL){
        printf("Error at file opening");
    }else{
        while (!feof(fptr)){
            if(feof(fptr)){
                break;
            }
            fscanf(fptr,"%d",&i);
            Root = insert(Root,i);

        }
    }

    return Root;
}

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