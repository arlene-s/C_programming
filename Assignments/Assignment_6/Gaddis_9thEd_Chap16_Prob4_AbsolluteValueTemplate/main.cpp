/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 30, 2021, 7:20 PM
 * Purpose: Create an absolute value function template that accepts an arugment
 *          and returns its absolute value
 */

#include <iostream>
using namespace std;

//Function prototypes
template <class T>      
T absVal(T num){        //Absolute value function template
    if(num<0)
        return num*-1;
    else
        return num;
}

int main(int argc, char** argv) {
    //Declare variables
    int val;
    
    //Map input to outputs
    cout<<"Enter a number: ";
    cin>>val;
    
    //Display results
    cout<<"The absolute value of the number is: "<<absVal(val); 

    return 0;
}

