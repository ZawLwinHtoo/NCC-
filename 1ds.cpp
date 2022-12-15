#include "stdio.h"
#include "stdlib.h"


struct node {
    int data;
    struct node *next;
};

void printData(struct node* myNode);
void insertAfter(struct node* prevNode, int newData);
int searchingData(struct node* myNode, int data);
struct node* atBeginning(struct node* myNode, int newData);
void Beginning(struct node** myNode, int newData);

int main() {
    struct node * head;
    struct node *one;
    struct node *two;
    struct node *three;

    one = static_cast<node *>(malloc(sizeof(struct node)));
    two = static_cast<node *>(malloc(sizeof(struct node)));
    three = static_cast<node *>(malloc(sizeof(struct node)));

    one-> data = 10 ;
    two-> data = 20 ;
    three-> data = 30 ;

    one-> next = two;
    two-> next = three;
    three-> next = NULL;

    printData(one);

    printf("After inserting,\n");
    printf("\n");
    insertAfter(one, 15);
    printData(one);
    printf("\n");
    printf("After inserting twice,\n");
    insertAfter(two, 25);
    printData(one);
    int result = searchingData(one, 20);
    if(result == 1){
        printf("We found. %d\n", result);
    } else{
        printf("Not found. %d\n", result);
    }
    printf("\n");

    printf("Putting node at the beginning first choice,\n");
    struct node* newLL= atBeginning(one, 5);
    printData(newLL);
    printf("\n");

    printf("Putting node at the beginning second choice,\n");
    Beginning(&one, 5);
    printData(one);
     return 0;
}


void printData(struct node* myNode){
    while( myNode != NULL){
        printf("data: %d\n", myNode->data);
        myNode= myNode->next;
    }
}

void insertAfter(struct node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("You data is NULL!\n Plz try again.");
        return;
    } else {
        struct node *newNode = static_cast<node *>(malloc(sizeof(struct node)));
        newNode->data = newData;

        newNode->next = prevNode->next;
        prevNode->next = newNode;

    }
}

int searchingData(struct node* myNode, int data){
    if (myNode == NULL){
        printf("Your node has nothing in it.");
        return 0;
    } else{
        int i= 1;
        while(myNode != NULL){

            if(myNode->data == data){
                printf("We found your data at node:%d\n", i);
                return 1 ;

            } else{
                myNode= myNode-> next;
                i++;
            }
        }
        return 0;
    }
}

struct node* atBeginning(struct node* myNode, int newData){
    struct node* beginNode = (struct node*) malloc(sizeof (struct node));
    beginNode -> data = newData;
    beginNode -> next = myNode;
    myNode = beginNode;
    return  myNode;
}

void Beginning(struct node** myNode, int newData){
    struct node* beginNode = (struct node*) malloc(sizeof (struct node));
    beginNode -> data = newData;
    beginNode -> next = (*myNode);
    (*myNode) = beginNode;
}