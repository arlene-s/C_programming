/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on October 18, 2021, 5:36 PM
 * Purpose: Use structures to store customer information and determine whether
 *          they have exceeded their checking account balance
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Customr.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
Customr *getDat(int &,int &);     //fill with customer info and return struct
void calcBal(Customr *,int,int);  //calculate the new balance
void print(Customr *,int,int);    //Print customer information
void destroy(Customr *);          

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    //Declare variables here
    int chcks=0, dpsits=0;          //Accumulate size of checks and deposits array
    Customr *custmr;                //Pointer to struct with customer info
    //Initialize variables here
    custmr=getDat(chcks, dpsits);   //Fill struct
    //Map inputs to outputs here, i.e. the process
    calcBal(custmr, chcks, dpsits); //Calculate new balance
    //Display the results
    print(custmr, chcks, dpsits);   //Print struct info
    //Deallocate memory
    destroy(custmr);                //Delete arrays and structure
    return 0;
}

void destroy(Customr *record){
    delete []record->checks;
    delete []record->dposits;
    delete record;
}

Customr *getDat(int &chcks, int &dpsits){
    int size=80;    //Initialize size for dynamic arrays - too big
    char again;     //User input
    
    Customr *record=new Customr;      //Allocate struct
    record->checks=new float[size];   //Allocate pointer
    record->dposits=new float[size];
    //Prompt user for bank info
    cout<<"Enter account number (5 digits max): ";
    cin>>record->accNum;
    while(record->accNum>99999){      //Can't be greater than 5 digits
        cout<<"Account number can only have a max of 5 digits"<<endl;
        cout<<"Enter account number: ";
        cin>>record->accNum;
    }
    cout<<"Enter your name: ";
    cin.ignore();
    getline(cin,record->name);
    cout<<"Enter balance at beginning of the month: ";
    cin>>record->begBal;
    cout<<"Enter address: ";
    cin.ignore();
    getline(cin, record->address);
    //Have user enter checks written until they don't want to
    do{
        cout<<"Enter a check written in the month: ";
        cin>>record->checks[chcks];
        chcks++;    //Increment for size
        cout<<"Do you want to enter another? (Y/N): ";
        cin>>again;
    }while(again=='Y' || again=='y');
    do{
        cout<<"Enter a deposit credited to you in the month: ";
        cin>>record->dposits[dpsits];
        dpsits++;
        cout<<"Do you want to enter another? (Y/N): ";
        cin>>again;
    }while(again=='Y' || again=='y');
    
    return record;
}

void calcBal(Customr *record, int chcks, int dpsits){
    float newBal=record->begBal;    //Initialize new balance to beginning balance
    
    for(int i=0; i<dpsits; i++)
        newBal+=record->dposits[i]; //Add deposits to balance
    for(int i=0; i<chcks; i++)
        newBal-=record->checks[i];  //Subtract balance from checks
    cout<<endl<<"New balance: $"<<newBal<<endl;
    if(newBal<0){
        cout<<endl;
        cout<<"Your account has been overdrawn"<<endl;
        cout<<"A fee of $25 will be processed"<<endl;
        newBal-=25;                 //Add 25 when new balance is negative
        cout<<"New balance with fee: $"<<newBal<<endl;
    }
}

void print(Customr *record, int chcks, int dpsits){
    cout<<endl;
    cout<<"Account number: "<<record->accNum<<endl;
    cout<<"Name: "<<record->name<<endl;
    cout<<"Address: "<<record->address<<endl;
    cout<<"Beginning Balance: $"<<record->begBal<<endl;
    cout<<"Checks: "<<endl;
    for(int i=0; i<chcks; i++)
        cout<<"$"<<record->checks[i]<<" ";
    cout<<endl;
    cout<<"Deposits: "<<endl;
    for(int i=0; i<dpsits; i++)
        cout<<"$"<<record->dposits[i]<<" ";
}