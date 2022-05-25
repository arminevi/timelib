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

#include "dateCalculator.h"
/* TODO: 
*  - include header file and c file for calculator 
*  - include structs 
*  - add to github 

    [*] => 1 Commit noch nicht gepusht: "Added header file"
    [*] => 2 Commits noch nicht gepusht: "Added dateCalculator.c"
*/



/* check if leap year
* @param int year
* @return 1 if leap year, 0 if no leap year, -1 if year is invalid
**/
/*
int is_leapyear(int year)
{
    int isLeapYear = 1;
    int noLeapYear = 0;
    int error = -1;
    int checker = 0;

    //error occurs if year is below 1582
    if (year < 1582){
        printf("\nJahr ist kleiner als 1582\n");
        return error;
    }
    
    //if else nesting
    if( year % 4 == 0) {
        if( year % 100 == 0) {
            if( year % 400 == 0) {
                checker = isLeapYear;
                //printf("Jahr ist Schaltjahr");
             }else {
                 //printf("Jahr kein Schaltjahr");
             }//end of 400
        }else {
            checker = isLeapYear;
            //printf("Jahr ist Schaltjahr");
        }//end of 100
    }else {
        //printf("Jahr kein Schaltjahr");
    }//end of 4

    return checker;
}//end of isLeapYear
*/

/*
* @param int day, month, year
* @return int number 1-31 OR -1 if date is invalid 
**/
/*
int exists_date(day, month, year)
{
    // date is invalid if below 1.1.1582 or after 31.12.2400
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1582 || year > 2400){
        return 0;
    }else{
        // date is valid 
        return 1;
    }
    
}//end of exists date 
*/

/* get total numbers of days
* @param int day, month, year 
* @return total number of days or if date is invalid return -1 
**/
/*
int day_of_the_year(day, month, year)
{

    // check date | if invalid return -1
    if (exists_date(day, month, year) == 0)
    {
        printf("\nif existst day Z.77\n");
        return -1;
    }    

    //array of all days of months
    int days_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int intReturn = 0;

    // because of array index
    month = month-1;

    // if is leap year add 1 
    if (is_leapyear(year) == 1){
        intReturn+=1;
    }

    if(month == 0){
        return intReturn+=day;
    }else{
        for(int i = 0; i<month; i++){
            intReturn = intReturn + days_per_month[i];
        }
        return intReturn+=day;
    }//end of if-else

}//end of day_of_the_year()
*/



/* get days of a month 
* @param int month, year 
* @return int get days of a month 
**/
/*
int get_days_for_month(month, year)
{

    //array of all days of months | redundant!
    int days_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int intReturn = 0;

    // because of array index
    month = month-1;

    // if is leap year add 1 
    if (is_leapyear(year) == 1){
        days_per_month[1]+=1;
    }

    return days_per_month[month];

}//end of get_days_for_month()
*/


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

        intDayOfYear = day_of_the_year(intUserDay, intMonthOfYear, intYear);

        if( is_leapyear(intYear) ){
            intDayOfYear+=intLeapYearAdd;
            //printf("Jahr ist Schaltjahr\n");
        }

        printf("\nHeute ist der %i. Tag des Jahres.\n\n", intDayOfYear);

    }//end of while
    return 0;
}//end of main

