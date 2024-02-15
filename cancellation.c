#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"combine.h"





void cancellation(struct Passenger *p[], struct seats fseats[]) {
    int input;
    int k = 0;
    int z;
    printf("Enter 1 to confirm your cancellation or to exit enter 0\n");//to confirm for cancellation
    scanf("%d", &input);
    if (input == 0){
        return;
    }
    else {
        long long int pnr;
        printf("Enter your PNR to cancel ticket\n");//asking the pnr
        scanf("%lld", &pnr);
        for(int i=0;i<420;i++)
        {//checking the passenger list for pnr
            for(int j=0;j<15;j++)
            {
                if(pnr==p[i][j].pnr)
                {
                   //removing the passenger list from the array
                    strcpy(p[i][j].gen, "0");
                    strcpy(p[i][j].FirstAndLastname, "0");
                    strcpy(p[i][j].MiddleName, "0");
                    strcpy(p[i][j].Email, "0");
                    p[i][j].age = 0;
                    p[i][j].pnr = 0;
                    fseats[i].seats--;
                    k = 1;
                    printf("SUCCESSFUL CANCELLATION");
                    FILE *backend=fopen("database.txt","w");//updating the databse and seats files accordingly
                for(int i=0;i<420;i++)
                {
                    for (int j=0;j<15;j++)
                    {
                    
                        fprintf(backend,"%s %s %d %d %s %s %s %s %d %lld \n",p[i][j].from,p[i][j].to,p[i][j].flight_number,p[i][j].date1,p[i][j].FirstAndLastname,p[i][j].MiddleName,p[i][j].gen,p[i][j].Email,p[i][j].age,p[i][j].pnr);
                    
                    }
                }
                fclose(backend);
                FILE *seats=fopen("seats.txt","w");
   
                for (int i=0;i<420;i++)
                {
                    fprintf(seats,"%s %s %d %d %d\n",fseats[i].from,fseats[i].to,fseats[i].flight_number,fseats[i].date1,fseats[i].seats);
                }
                fclose(seats);
                    break;
                }
            }
        }
    }
                   
                
            
    if (k == 1) {
        return;//exit
    }
        
    if (k != 1) {
        printf("Wrong pnr");//if pnr is not found
    }
    }


    