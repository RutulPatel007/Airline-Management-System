#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"combine.h"


void web_check_in(struct Passenger * p[]){
    int k=0;
    
    while(1){
    long long int  pnr;
	printf("Enter your PNR\n");
	scanf("%lld",&pnr);//loop to check the pnr in the passenger list
        for(int i=0;i<420;i++){
            for(int j=0;j<15;j++){
                if(p[i][j].pnr==pnr){
                    printf("WEB CHECK-IN SUCCESSFUL\n");//success
                    k=1;
                    return;
                }
            }
        }
        if(k==0){
                   printf("Wrong pnr");//if pnr is not in passenger list
                }
    }
}