/**
 * Armin Saderi
 *
 * Tag des Jahres Rechner
 *
 * 03.05.2022
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isLeapYear(int year)
{
    bool checker = false;
    //if else nesting
    if( year % 4 == 0) {
        if( year % 100 == 0) {
            if( year % 400 == 0) {
                checker = true;
                //printf("Jahr ist Schaltjahr");
             }else {
                 //printf("Jahr kein Schaltjahr");
             }//end of 400
        }else {
            checker = true;
            //printf("Jahr ist Schaltjahr");
        }//end of 100
    }else {
        //printf("Jahr kein Schaltjahr");
    }//end of 4

    return checker;
}//end of isLeapYear


int getDayOfYear(intUserMonth){
    //array of all days of months
    int days_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int intReturn = 0;

    for(int i = 0; i<intUserMonth; i++){
        intReturn = intReturn + days_per_month[i];
    }//end of for

    return intReturn;
}

int main()
{
    //for the loop. if value other than 1 programm ends
    int intTrue = 1;

    while(intTrue == 1){

        //declaration of variables
        int intYear = 0;
        int intMonthOfYear = 0;
        int intUserDay = 0;
        int intDayOfYear = 0;
        int intLeapYearAdd = 1;

        //intro
        printf("*** Tag des Jahres ***\n");

        //get year only relevant for leap year calculation (add 1 or not)
        printf("Geben Sie das Jahr ein: ");
        scanf("%i", &intYear );

        //get month
        printf("Geben Sie den Monat ein: ");
        scanf("%i", &intMonthOfYear );

        //get day
        printf("Geben Sie den Tag ein: ");
        scanf("%i", &intUserDay );

        intDayOfYear = getDayOfYear(intMonthOfYear);

        //calculation FALSE
        intDayOfYear-=intUserDay;
        printf("\n intDayOfYear = %i\n", intDayOfYear);

        if( isLeapYear(intYear) ){
            intDayOfYear+=intLeapYearAdd;
            //printf("Jahr ist Schaltjahr\n");
        }

        printf("Heute ist der %i. Tag des Jahres.\n", intDayOfYear);

    }//end of while
    return 0;
}//end of main
