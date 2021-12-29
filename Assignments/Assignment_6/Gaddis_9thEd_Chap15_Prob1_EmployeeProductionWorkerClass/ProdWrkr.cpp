/* 
 * File:   ProdWrkr.h
 * Author: Arlene Sagaoinit
 * Created on November 28, 2021, 8:34 PM
 * Purpose: Production worker class member functions
 */

#include "ProdWrkr.h"
#include <iostream>
using namespace std;

//Call base class default constructor
ProdWrkr::ProdWrkr():Employee(){
    setWrkr(1,0.0);     //Initialize production worker's shift info 
    //shift=1 -> day shift
    //shift=2 -> night shift
}

//When arguments are passed with object definition, call base class default constructor
ProdWrkr::ProdWrkr(int shiftNum, float pay):Employee(){
    setWrkr(shiftNum,pay);  //Initialize member variables
}

void ProdWrkr::setWrkr(int shiftNum, float pay){
    if(shiftNum==1||shiftNum==2)    //shift number can only be 1 or 2
        shift=shiftNum;
    payRate=pay;
}

//Display worker's shift info
void ProdWrkr::display(){
    //Call base class function to display employee's personal info first
    Employee::display();
    //Then the derived class's info
    cout<<"Shift: "<<(shift==1?"Day shift":
                      shift==2?"Night shift":
                               "Should not get here")<<endl;
    cout<<"Worker's pay rate: "<<payRate<<endl;
}
