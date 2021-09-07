/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on September 6, 2021, 3:17 PM
 * Purpose: Convert fahrenheit temperature to celsius and display table
 *          of temperatures 0 through 20
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
float celsius(float); //Converts fahrenheit temp to celsius

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<"Fahrenheit\t"<<"Temperature"<<endl
         <<"---------------------------"<<endl;
    
    for(int i=0;i<=20;i++){                 //Display table of conversions from temperatures 0-20
        cout<<i<<"\t\t"<<celsius(i)<<endl;  //Call conversion function and display results
    }
    
    return 0;
}

float celsius(float F){     //Pass in temperature in fahrenheit
    return ((5*(F-32))/9);  //Return temperature in celsius using conversion equation
}