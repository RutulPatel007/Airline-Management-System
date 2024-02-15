#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>


struct Passenger
{
    char FirstAndLastname[20];
    char MiddleName[20];
    char gen[10];
    char Email[20];
    int age;
    long long int pnr;
    int flight_number;          //Sanchit  flight _number to filght_number
    char from[20];
    char to[20];
    int date1;
    

};

struct seats
{
    char from[20];
    char to[20];
    int flight_number;
    int seats;
    int date1;


};


int valid_date(int date, int mon, int year);
int diff(int day1,int mon1 ,int year1,int day2,int mon2,int year2);
void print_date1_time();
void book(struct Passenger *a[],struct seats fseats[]);
void cancellation(struct Passenger *p[], struct seats fseats[]);
void web_check_in(struct Passenger * p[]);
int dynamic_pricing(int m,int d);
void Passengerdetails(int n,struct Passenger *a[],struct seats fseats[],int z,int k);
void payment_complete();

