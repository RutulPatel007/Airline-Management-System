#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"combine.h"

void print_date1_time(){
    time_t t;   
    time(&t);
    printf("\nThe current date1 and time is: %s", ctime(&t));
}