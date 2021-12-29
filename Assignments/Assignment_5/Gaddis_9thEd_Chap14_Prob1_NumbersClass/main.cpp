/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 15, 2021, 8:07 PM
 * Purpose: Create a class called numbers that will translate an integer value
 *          from 0-9999 into an english description of the number
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//User libraries
#include "Numbers.h"

int main(int argc, char** argv) {
    //Declare variables
    int numb;
    
    //Initialize variables
    cout<<"Enter a number between 0-9999: ";
    cin>>numb;
    
    //Map input to outputs
    Numbers nums(numb);
    
    //Display results
    nums.print();

    return 0;
}

