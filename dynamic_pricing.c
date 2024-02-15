//ARYAMAN PATHAK IMT2022513
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"combine.h"

//pricing rules
//if d is difference between system date and flight date
//price depends upon d

int dynamic_pricing(int m,int d){
    if(d==1||d==2){
        return m*2;
    }

    else if(d==3||d==4){
        return m*1.75;
    }

    else if(d==5||d==6){
        return m*1.5;
    }

    else if(d==7){
        return m;
    }
}
