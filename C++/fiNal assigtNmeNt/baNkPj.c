//
// Created by zl_shit_h on 30/05/23.
//

#include "stdio.h"
#include "AVL_for_bank.h"



int main(){
    db = (struct data*) malloc(sizeof (struct data));

    loading_data_from_file_to_AVL();
    while (true){
        printing_data(root);
         welcome();

    }
    return 0;
}