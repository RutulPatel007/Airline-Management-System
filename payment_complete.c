//RISHI PATEL IMT2022041

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"combine.h"

void payment_complete(){
    printf("Welcome to the payment page!\n");
    printf("Please enter your card details.\n");
    fflush(stdin);
    
    long long int card_number = 0;
    printf("Please enter your 16-digit card number: ");
    scanf("%lld", &card_number);
    fflush(stdin);
    int c; 

    if (card_number < 1000000000000000 || card_number >= 10000000000000000){//checkig for 16 digit
        printf("Invalid card number. Please enter a 16-digit card number.\n");
        return;
    }
    int cvv = 0;
    printf("Please enter your 3-digit CVV: ");
    scanf("%d", &cvv);
    fflush(stdin);  

    if (cvv < 100 || cvv >= 1000){//checking for 3 digit
        printf("Invalid CVV. Please enter a 3-digit CVV.\n");
        return;
    }
    printf("Payment successful.\n");
}


