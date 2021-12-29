/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on June 21, 2021, 11:19 AM
 * Purpose:  Develop a Template to be copied
 *           for all future programs in CSC/CIS 5
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Scores.h"
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int scr1, scr2, scr3;
    
    //Initialize variables here
    cout<<"Enter first score: ";
    cin>>scr1;
    cout<<"Enter second score: ";
    cin>>scr2;
    cout<<"Enter third score: ";
    cin>>scr3;
    //Scores test(scr1,scr2,scr3);
    Scores test(scr1,scr2,scr3);
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<"Score 1: "<<test.getSc1()<<endl;
    cout<<"Score 2: "<<test.getSc2()<<endl;
    cout<<"Score 3: "<<test.getSc3()<<endl;
    cout<<"Average: "<<test.getAvg()<<endl;
    
    return 0;
}