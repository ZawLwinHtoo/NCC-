#include "stdio.h"
#include "stdlib.h"

int main(){
    int P,N,D,Q,Sum;
    printf("Enter pennies;");
    scanf( "%d", &P);
    P = P*1;
    printf("Enter Nickle");
    scanf("%d", &N);
    N= N*5;
    printf("Enter Dim");
    scanf("%d", &D);
    D = D*10;
    printf("Enter Quatret");
    scanf("%d", &Q);
    Q = Q*25;
    Sum = P + N + D + Q;
    if (Sum == 100){
        printf("Win");
    } else if(Sum<100){
        printf("Insufficient");
    } else {
        printf ("Over");
    }


    return 0 ;
}