/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on August 28, 2021, 9:34 AM
 * Purpose: Convert temperature in celsius to fahrenheit
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
    float tempCel;//Temperature in celsius
    float tempFah;//Temperature in fahrenheit
    
    //Initialize variables here

    //Map inputs to outputs here, i.e. the process
    cout<<"Enter a temperature in degrees celsius: ";
    cin>>tempCel;
    
    tempFah=(9/5.0)*tempCel+32;//Formula for celsius to fahrenheit conversion
       
    //Display the results
    cout<<"Temperature in degrees fahrenheit: "<<tempFah<<endl;
    return 0;
}
