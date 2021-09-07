/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on August 29, 2021, 11:33 AM
 * Purpose: Determine the number of days in a given month and year
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    char days[]={31,28,31,30,31,30,31,31,30,31,30,31};//Number of days in each month
    unsigned short month;   //Input from user of range integers, 1-12
    unsigned short year;    //Input of year from user
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Enter the month you want to report the number of days (1-12): ";
    cin>>month;
    
    while(month<1 || month>12){ //Error checking input, subtract 48 from month to get integer
        cout<<"Input invalid"<<endl;
        cout<<"Enter the month you want to report the number of days (1-12): ";
        cin>>month;
    }
 
    cout<<"Enter the year: ";
    cin>>year;
    
    while(year<1000 || year>2021){
        cout<<"Input invalid"<<endl;
        cout<<"Enter the year: ";
        cin>>year;
    }
    
    if(year%100==0){        //Determine if year inputted is a leap year
        if(year%400==0)
            days[1]=29;     //If it is, reassign month of February(index 1) to 29 days
    }else{               
        if(year%4==0)
            days[1]=29;
    }

    //Display the results
    cout<<"Days in the month: "<<static_cast<int>(days[month-1])<<endl;
    
    return 0;
}