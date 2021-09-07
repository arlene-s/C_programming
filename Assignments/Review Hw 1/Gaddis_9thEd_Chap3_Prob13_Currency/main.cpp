/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on August 28, 2021, 9:55 AM
 * Purpose: Convert U.S. dollar amounts to yen and euros
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //fixed,setprecision(),showpoint
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    const float yen_per_dollar=109.83; //Most up to date exchange rates
    const float euros_per_dollar=0.85;
    
    float dollar,yen,euros; //Currency amounts in U.S dollar, Japanese yen, and euros
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Enter U.S dollar amount: ";
    cin>>dollar;
    
    yen=dollar*yen_per_dollar; //Formula for U.S dollar amount to yen
    euros=dollar*euros_per_dollar; //Formula for U.S dollar amount to euros
    
    //Display the results
    cout<<fixed<<setprecision(2)<<showpoint;
    
    cout<<"U.S dollar amount in yen: "<<yen<<endl;
    cout<<"U.S dollar amount in euros: "<<euros<<endl;
    
    return 0;
}
