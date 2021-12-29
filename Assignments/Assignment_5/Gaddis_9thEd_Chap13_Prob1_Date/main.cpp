/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Purpose: Create a class called date that takes in the day, month, and year,
 *          and display in three different formats
 * Created on November 1, 2021, 5:13 PM
 */

//System libraries
#include <iostream>  //Input/Output library[
using namespace std; //STD Name-space where Library is compiled

//User Libraries
#include "Date.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    Date date;
    int day, mnth, yr;
    //Initialize variables here

    //Map inputs to outputs here, i.e. the process
    cout<<"Enter the day: ";
    cin>>day;
    date.setDay(day);
    cout<<"Enter the month: ";
    cin>>mnth;
    date.setMnth(mnth);
    cout<<"Enter the year: ";
    cin>>yr;
    date.setYear(yr);
    
    //Display the results
    cout<<endl;
    cout<<date.getMnth()<<"/"<<date.getDay()<<"/"<<date.getYear()<<endl;
    cout<<date.strMnth()<<" "<<date.getDay()<<", "<<date.getYear()<<endl;
    cout<<date.getDay()<<" "<<date.strMnth()<<" "<<date.getYear()<<endl;
    
    return 0;
}

