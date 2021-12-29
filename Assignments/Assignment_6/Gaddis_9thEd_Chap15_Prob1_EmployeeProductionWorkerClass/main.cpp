/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 28, 2021, 8:15 PM
 * Purpose: Create an Employee class and and a ProdWrkr class that is derived
 *          from the Employee class 
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
#include "ProdWrkr.h"

int main(int argc, char** argv) {
    //Declare variables
    int shift;
    float pay;
    string name,num,date;
    
    //Map inputs to outputs
    cout<<"Enter your shift number (Day shift=1 Night shift=2): ";
    cin>>shift;
    cout<<"Enter your pay rate: ";
    cin>>pay;
    
    //Create an object from derived class
    ProdWrkr worker(shift,pay);
    
    cout<<"Enter your name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter employee number: ";
    cin>>num;
    cout<<"Enter hire date(mmddyyyy): ";
    cin>>date;
    
    //Enter worker's personal info using base class's member functions
    worker.setEmp(name,num,date);
    
    //Display information
    cout<<endl;
    cout<<"Here is your information: "<<endl<<endl;
    worker.display();   //Displays base class info and worker class info

    return 0;
}

