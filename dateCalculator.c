#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* check if leap year
* @param int year
* @return 1 if leap year, 0 if no leap year, -1 if year is invalid
**/
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


/* @param int day, month, year
* @return int number 1-31 OR -1 if date is invalid 
**/
int exists_date(int day, int month, int year)
{
    // date is invalid if below 1.1.1582 or after 31.12.2400
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1582 || year > 2400){
        return 0;
    }else{
        // date is valid 
        return 1;
    }
    
}//end of exists date 


/* get total numbers of days
* @param int day, month, year 
* @return total number of days or if date is invalid return -1 
**/
int day_of_the_year(int day, int month, int year)
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


/* @param int month, year 
* @return int get days of a month 
**/

int get_days_for_month(int month, int year)
{

    //array of all days of months | redundant!
    int days_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int intReturn = 0;

    // because of array index
    month = month-1;

    // if is leap year add 1 fis_leapyear
    if (is_leapyear(year) == 1){
        days_per_month[1]+=1;
    }

    return days_per_month[month];

}//end of get_days_for_month()