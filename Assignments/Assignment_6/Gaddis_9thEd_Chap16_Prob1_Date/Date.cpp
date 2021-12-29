/* 
 * File:   Date.h
 * Author: Arlene Sagaoinit
 * Created on November 29, 2021, 7:42 PM
 * Purpose: Date class chapter 13 problem 1 modified to include exceptions
 */

#include "Date.h"
#include <iostream>
using namespace std;

//Modified to throw exception
void Date::setDay(int d){
    if(d<1||d>31)
        throw InvalidDay(d);
    else
        day=d;
}
//Modified to throw exception
void Date::setMnth(int m){
    if(m<1||m>12)
        throw InvalidMnth(m);
    else
        month=m;
}
void Date::setYear(int y){
    year=y;
}
int Date::getDay()const{
    return day;
}
int Date::getMnth()const{
    return month;
}
int Date::getYear()const{
    return year;
}
string Date::strMnth(){
    string mnth;
    mnth=month==1?"January":
         month==2?"February":
         month==3?"March":
         month==4?"April":
         month==5?"May":
         month==6?"June":
         month==7?"July":
         month==8?"August":
         month==9?"September":
         month==10?"October":
         month==11?"November":
         month==12?"December":"";
    return mnth;
}
