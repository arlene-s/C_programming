/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 29, 2021, 7:42 PM
 * Purpose: Modify Date class in chapter 13 problem 1 to have exceptions
 */

//System libraries
#include <iostream>  //Input/Output library[
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "Date.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void display(Date &);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    Date date;
    int day, mnth, yr;

    //Map inputs to outputs here, i.e. the process
    cout<<"Enter the day: ";
    cin>>day;
    cout<<"Enter the month: ";
    cin>>mnth;
    cout<<"Enter the year: ";
    cin>>yr;
    
    date.setYear(yr);               //Set the year
    try{
        date.setDay(day);           //Set day, throws an exception if input invalid
        date.setMnth(mnth);         //Set month, throws an exception if input invalid
        //Display the results
        display(date);
    }catch(Date::InvalidDay e){     //When day is invalid
        cout<<"Error: "<<e.getInvalid()
            <<" is an invalid input for the day"<<endl;
    }catch(Date::InvalidMnth e){    //When month is invalid
        cout<<"Error: "<<e.getInvalid()
            <<" is an invalid input for the month"<<endl;
    }
    
    return 0;
}

void display(Date &d){
    cout<<endl;
    cout<<d.getMnth()<<"/"<<d.getDay()<<"/"<<d.getYear()<<endl;
    cout<<d.strMnth()<<" "<<d.getDay()<<", "<<d.getYear()<<endl;
    cout<<d.getDay()<<" "<<d.strMnth()<<" "<<d.getYear()<<endl;
}