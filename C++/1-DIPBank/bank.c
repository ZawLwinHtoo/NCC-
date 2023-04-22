//
// Created by HUAWEI on 3/27/2023.
//
#include "stdio.h"
#include "zoom_online_bank.h"


int main(){

    space_counter();
    loadingAllDataFromFile();
    calculate_amount_same_day(0);
    //printingAllData();
    // welcome();
current_data_to_transfer(3000);
    return 0;
}



