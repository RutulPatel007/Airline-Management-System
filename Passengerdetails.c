//RISHI PATEL IMT2022041

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"combine.h"


void Passengerdetails(int n,struct Passenger *a[],struct seats fseats[],int z,int k){
    int l=0;//variable to keep track the number of passenger
    while(l<n){
            printf("Enter the  Passenger-%d First Name: ", l+1);
            scanf("%s",a[k][fseats[k].seats].FirstAndLastname);
            fflush(stdin);//clearing inputs
            printf("\n");

            printf("Enter the  Passenger-%d Last Name: ", l+1);
            scanf("%s",a[k][fseats[k].seats].MiddleName);
            fflush(stdin);
            printf("\n");

            printf("Enter the  Passenger-%d Gender: ", l+1);
            scanf("%s",a[k][fseats[k].seats].gen);
            fflush(stdin);
            printf("\n");

            printf("Enter the  Passenger-%d Email: ", l+1);
            scanf("%s",a[k][fseats[k].seats].Email);
            fflush(stdin);
            printf("\n");

            printf("Enter the Passenger-%d Age: ", l+1);
            scanf("%d",&a[k][fseats[k].seats].age);
            fflush(stdin);
            printf("\n");
              
            fseats[k].seats++;//inncreasing the seats array element by 1
            l++;
    }    
}
   
