/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on September 6, 2021, 2:02 PM
 * Purpose: Predict the size of a population of organisms throughout a number of days
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
    unsigned int numOrg;    //Starting number of organisms
    float popInc;           //Daily population increase (percent)
    unsigned int numDays;   //Number of days organisms will multiply
    unsigned int dailyPop;  //Number of organisms increased per day
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Please enter the starting number of organisms: ";
    cin>>numOrg;
    while(numOrg<2){ //Input validation, needs to be 2 or greater
        cout<<"Please enter valid starting population size (2 or greater): ";
        cin>>numOrg;
    }
    
    cout<<"Please enter organisms active daily population increase (percent): ";
    cin>>popInc;
    while (popInc<0){ //Input validation, needs to be 0 or greater
        cout<<"Please enter valid daily population increase (0 or greater): ";
        cin>>popInc;
    }
    
    cout<<"Enter number of days to report: ";
    cin>>numDays;
    while(numDays<1){ //Input validation, needs to be 1 or greater
        cout<<"Please enter valid number of days (1 or greater): ";
        cin>>numDays;
    }
    
    dailyPop=numOrg*popInc; //Calculate number of organisms multiplied per day
    
    //Display the results for each day
    for(int i=0;i<numDays;i++){
        numOrg+=dailyPop;
        cout<<"Day "<<i+1
             <<" Population size: "<<numOrg<<endl;
    }
    return 0;
}