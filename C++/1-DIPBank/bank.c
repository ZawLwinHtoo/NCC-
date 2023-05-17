//
// Created by zl_shit_h on 15/05/23.
//

#include "stdio.h"
#include "zoom_online_bank.h"


int main(){
    space_counter();
    loadingAllDataFromFile();
//    current_data_to_transfer(3000);
//    calculate_amount_same_day(0);
//    get_limit_amount(0);
//    printf("trans limit: %d",trans_limit);
    printingAllData();
    welcome();

    return 0;
}