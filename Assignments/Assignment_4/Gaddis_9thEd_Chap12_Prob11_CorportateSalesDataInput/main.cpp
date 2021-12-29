/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on December 9, 2021, 8:42 PM
 * Purpose: Create a structure of a company divisions info. Get user input and
 *          store info. Write contents to file.
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <fstream>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "CompDiv.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    CompDiv company;
    CompDiv comp;
    int numQuarts=4;
    fstream file;
    
    //Initialize variables here
    company.quartr=new int[numQuarts];
    company.qSales=new int[numQuarts];
    
    comp.quartr=new int[numQuarts];
    comp.qSales=new int[numQuarts];
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Enter company division: ";
    cin>>company.divName;
    for(int i=0; i<numQuarts;i++){
        cout<<"Enter quarter number: ";
        cin>>company.quartr[i];
        cout<<"Enter sales for the quarter: ";
        cin>>company.qSales[i];
    }
    
    //Write to file
    
    file.open("sales.txt",ios::out|ios::binary);
    file.write(reinterpret_cast<char*>(&company),sizeof(company));
    file.close();
    //Read from file
    
    file.open("sales.txt",ios::in|ios::binary);
    file.read(reinterpret_cast<char*>(&comp),sizeof(comp));
    //Close file
    file.close();
    
    //Display the results
    cout<<endl;
    cout<<"Division name: "<<comp.divName<<endl;
    for(int i=0; i<4;i++){
        cout<<"Quarter #"<<comp.quartr[i]<<endl;
        cout<<"Quarter Sale: "<<comp.qSales[i]<<endl;
    }
   
    
    //Delete memory
    delete []company.quartr;
    delete []company.qSales;
    delete []comp.quartr;
    delete []comp.qSales;
    
    return 0;
}
