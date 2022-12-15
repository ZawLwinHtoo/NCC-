#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(){

    int i=0 ;
    int pass[10] ;
    int count=0 ;
    srand(time(NULL)) ;

    for (i=0; i<=100; i++){
        int randomNumber= rand()%90;
        if (randomNumber>=64 && randomNumber<=90) {
            count++ ;
            pass[count] = randomNumber;
            printf("%d",count );
            printf(" %d ",i) ;
            printf("Random number=%c\n",randomNumber) ;

            if (count==10) {
                break ;
            }
        }


    }
        printf("our generated password is;") ;
        for (count=0; count<=10; count++){
            printf("%c",pass[count]);
        }

    return 0;
}