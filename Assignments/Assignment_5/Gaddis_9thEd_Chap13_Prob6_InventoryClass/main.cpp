/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 6, 2021, 11:19 PM
 * Purpose:  Develop a Template to be copied
 *           for all future programs in CSC/CIS 5
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Invntry.h"

//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void display(Invntry);
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    //Create item object with default constructor;
    Invntry item1;
    
    //Initialize variables here
    //Create an item with second constructor
    Invntry item2(132,12,7);
    
    //Create an item using mutator functions
    Invntry item3;      //Default constructor assigns members to 0
    item3.setItmNum(4592);
    item3.setQuant(46);
    item3.setCost(23.5);
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    display(item1);
    display(item2);
    display(item3);
    
    return 0;
}
void display(Invntry item){
    cout<<left;
    cout<<setw(20)<<"Item Number:"<<item.getItmNum()<<endl;
    cout<<setw(20)<<"Quantity:"<<item.getQuant()<<endl;
    cout<<setw(20)<<"Cost:"<<"$"<<item.getCost()<<endl;
    cout<<setw(20)<<"Total cost:"<<"$"<<item.getTotCost()<<endl;
    cout<<endl;
}