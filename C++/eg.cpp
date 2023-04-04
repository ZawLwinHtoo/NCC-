void myStrongPassword (char pass[50]){

    int i=0;
    int specialChar = 0;
    int smallChar = 0;
    int capChar = 0;
    int numChar = 0;
    int passCounter = charCounting(pass);

    while (strongPass == -1){
        if ( i == passCounter){
            strongPass = -1;
            break;
        }
        if ( pass[i] >=33 && pass[i] <=42){

            specialChar++;
        } else if ( pass[i] >= 48 && pass[i] <= 57){

            numChar++;
        } else if ( pass[i] >= 65 && pass[i] <= 90){

            capChar++;
        } else if (pass[i] >= 97 && pass[i] <= 122) {

            smallChar++;
        }
        i++;

        if (specialChar >0 && numChar >0 && capChar > 0 && smallChar > 0){
            strongPass == 1 ;
        }
    }



}void myStrongPassword (char pass[50]){

    int i=0;
    int specialChar = 0;
    int smallChar = 0;
    int capChar = 0;
    int numChar = 0;
    int passCounter = charCounting(pass);

    while (strongPass == -1){
        if ( i == passCounter){
            strongPass = -1;
            break;
        }
        if ( pass[i] >=33 && pass[i] <=42){

            specialChar++;
        } else if ( pass[i] >= 48 && pass[i] <= 57){

            numChar++;
        } else if ( pass[i] >= 65 && pass[i] <= 90){

            capChar++;
        } else if (pass[i] >= 97 && pass[i] <= 122) {

            smallChar++;
        }
        i++;

        if (specialChar >0 && numChar >0 && capChar > 0 && smallChar > 0){
            strongPass == 1 ;
        }
    }



}

void myStrongPassword(char pass[50]) {

    int i = 0;
    int special = 0;
    int numberChar = 0;
    int capChar = 0;
    int smallChar = 0;
    int pass_counter = charCounting(pass);
    while (strongPass == -1) {
        if (i == pass_counter) {
            strongPass = -1;
            break;
        }
        if (pass[i] >= 33 && pass[i] <= 42) {

            special++;
        } else if (pass[i] >= 48 && pass[i] <= 57) {

            numberChar++;

        } else if (pass[i] >= 65 && pass[i] <= 90) {

            capChar++;
        } else if (pass[i] >= 97 && pass[i] <= 122) {

            smallChar++;
        }
        i++;
        if (special > 0 && numberChar > 0 && capChar > 0 && smallChar > 0) {
            strongPass = 1;
        }
    }


}