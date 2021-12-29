/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 6, 2021, 8:44 PM
 * Purpose: Create a retail item object and display its contents
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Item.h"
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void display(Item);
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    
    //Initialize variables here
    //Create three objects from item class
    Item item1("Jacket",12,59.95);
    Item item2("Designer Jeans",40,34.95);
    Item item3("Shirt",20,24.95);
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<setw(15)<<" ";
    cout<<left<<setw(20)<<"Description"<<setw(20)<<"Units On Hand"<<"Price"<<endl;
    display(item1);
    display(item2);
    display(item3);
    return 0;
}
void display(Item item){
    cout<<left<<setw(15);
    cout<<"Item #1"<<setw(20)<<item.getDesc()<<setw(20)<<item.getUnits()<<item.getPrice()<<endl;
}
