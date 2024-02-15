#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"combine.h"

int main(){
    FILE *seats=fopen("seats.txt","r");//open seats file
    struct seats fseats[420];//array of seats

    for (int i=0;i<420;i++){//scan seats file
        fscanf(seats,"%s %s %d %d %d",fseats[i].from,fseats[i].to,&fseats[i].flight_number,&fseats[i].date1,&fseats[i].seats);
    }

    fclose(seats);//close seats file
    struct Passenger p[15];//passenger
    struct Passenger * flights[420];//array of passengers
    for(int i=0;i<420;i++){ //assign passengers memory
        flights[i]=(struct Passenger *)malloc(15*sizeof(struct Passenger));
    }
    FILE *backend=fopen("database.txt","r");//open database file
    for(int i=0;i<420;i++){// scan database file
        for(int j=0;j<15;j++){
            fscanf(backend,"%s %s %d %d %s %s %s %s %d %lld ",flights[i][j].from,flights[i][j].to,&flights[i][j].flight_number,&flights[i][j].date1,flights[i][j].FirstAndLastname,flights[i][j].MiddleName,flights[i][j].gen,flights[i][j].Email,&flights[i][j].age,&flights[i][j].pnr);
        }
    }
    fclose(backend);//close database file

    int m=1;// variable  for user to go back or exit program
    while( m==1){//loop   for user to go back or exit program
        print_date1_time();//printing current date and time 
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");//printing menu
        printf("\n||||||||||||||WELCOME TO KAATIL ONLINE TRAVEL AGENCY|||||||||||||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n\n\t\tPlease choose an option from the following:");
        printf("\n\n\t\t 1. BOOK A FLIGHT TICKET");
        printf("\n\n\t\t 2. CANCELLATION");
	    printf("\n\n\t\t 3. MY ACCOUNT");
	    printf("\n\n\t\t 4. Web check-in");
        printf("\n\n\t\t\t\t\t\tENTER YOUR CHOICE HERE");      
        int choice=0;//choice variable
        scanf("%d", &choice);
        switch (choice){//switch statement for choice
		case 1:
            m=0;
			book(flights,fseats);//calling book function
            printf("PLEASE ENTER 1 TO GO BACK TO MAIN MENU \n");
            printf("PLEASE ENTER 0  TO EXIT \n");
            scanf("%d",&m);
            break;
			
		case 2:
            m=0;
            cancellation(flights,fseats);//calling cancellation function
            break;
			
		case 3:
            m=0;
			long long int l;
            printf("WHAT IS YOUR PNR?\n ");//asking for user input
            scanf("%lld",&l);
            for(int i=0;i<420;i++){//loop to go through passenger list for pnr
                for(int j=0;j<15;j++){
                    if(flights[i][j].pnr==l){
                        time_t t;
                        t = time(NULL);
                        struct tm tm = *localtime(&t);
                        int d=tm.tm_mday+flights[i][j].date1;//for taking system date 
                        int m=tm.tm_mon+1;
                        int y=tm.tm_year+1900;
                        printf("First Name - %s\n",flights[i][j].FirstAndLastname);
                        printf("Last Name - %s\n",flights[i][j].MiddleName);
                        printf("Age - %d\n",flights[i][j].age);
                        printf("Email - %s\n",flights[i][j].Email);
                        printf("PNR - %lld\n",flights[i][j].pnr);
                        printf("Flight From - %s\n",flights[i][j].from);
                        printf("Flight To - %s\n",flights[i][j].to);
                        printf("Flight On - %d-%d-%d\n",d,m,y);
                        printf("Have a Nice Journey to\n");//priting user the details of the flight
                    }
                }
            }
            printf("PLEASE ENTER 1 TO GO BACK TO MAIN MENU \n");
            printf("PLEASE ENTER 0 TO EXIT \n");
            scanf("%d",&m);
            break;

			
		case 4:
		{       m=0;
				  web_check_in(flights);//calling web checkin function
                  printf("PLEASE ENTER 1 TO GO BACK TO MAIN MENU \n");
                  printf("PLEASE ENTER 0 TO EXIT \n");
                  scanf("%d",&m);

                  break;
				  
		}
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");//defaut case
			printf("\n\n\t Please choose from the given options");
		}
	}
}

