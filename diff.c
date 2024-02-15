#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"combine.h"


int diff(int day1,int mon1 ,int year1,int day2,int mon2,int year2){
    int ddiff,mdiff, ydiff;

    if(!valid(day1, mon1, year1)){
        printf("First date is invalid.\n");        
    }

    if(!valid(day2, mon2, year2)){
        printf("Second date is invalid.\n");
        exit(0);
    }       

    if(day2 < day1){             
        if (mon2 == 3){
            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)){     //  check whether year is a leap year
                day2 += 29;
            }
            else{
                day2 += 28;//february
            }                        
        }
       
        else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) {
           day2 += 30; 
        }
        //  days from Jan or Mar or May or July or Aug or Oct or Dec
        else{
           day2 += 31;
        }
        mon2 = mon2 - 1;
    }
    if (mon2 < mon1){
        mon2 += 12;
        year2 -= 1;
    }     
    ddiff = day2 - day1;
   mdiff = mon2 - mon1;
    ydiff = year2 - year1;

    if(ydiff>0||mdiff>0){
        return 0;
    }
    else if(ddiff<8){
        return ddiff;//since we are booking flights for 7 day from system date
    }
    else{
        return 0;
    }
    return 0; // return 0 to operating system
}




// function to check whether a date is valid or not
int valid(int day, int mon, int year){
    int is_valid = 1, is_leap = 0;
    if (year >= 1800 && year <= 9999) {

        //  leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            is_leap = 1;
        }

        // mon is between 1 and 12
        if(mon >= 1 && mon <= 12){
            // check for days in feb
            if (mon == 2){
                if (is_leap && day == 29) {
                    is_valid = 1;
                }
                else if(day > 28) {
                    is_valid = 0;
                }
            }           
            // 
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
                if (day > 30){
                    is_valid = 0;
                }
            }

            // check for days in other months 
          
            else if(day > 31){            
                is_valid = 0;
            }        
        }
        else{
            is_valid = 0;
        }
    }
    else{
        is_valid = 0;
    }
    return is_valid;
}