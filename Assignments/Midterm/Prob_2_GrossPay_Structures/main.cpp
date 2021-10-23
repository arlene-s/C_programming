/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on October 20, 2021, 7:48 PM
 * Purpose:  Determine the gross pay for each worker and display in a check format
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "EmpInfo.h"  //Structure of employee
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void getDat(EmpInfo &);     //Grabs input
float calcPay(EmpInfo &);   //Calculates gross pay
void print(EmpInfo);        //Print check
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int size;                   //Number of employees
    EmpInfo *array;             //pointer to struct
    //Initialize variables
    cout<<"Enter the number of employees: ";
    cin>>size;
    array=new EmpInfo[size];    //Create array of structures
    //Map inputs to outputs
    for(int i=0; i<size; i++){
        getDat(array[i]);       //Grab struct info and store into each element
        //Display the results
        print(array[i]);        //Print check
    }
    //Deallocate
    delete []array;
    
    return 0;
}

void print(EmpInfo ary){ 
    cout<<endl<<ary.address<<endl;
    cout<<"Pay to the"<<endl
        <<"Order of "<<setw(15)<<ary.name<<setw(10)<<"$"<<ary.grosPay<<endl;
    //Convert the amount into english words
    int whleNum=ary.grosPay;   //Whole number
    if(ary.grosPay>=1 && ary.grosPay<=5000){
        unsigned char n1000s,n100s,n10s,n1s;
        n1000s=whleNum/1000;   //Shift 3 places to the left
        n100s=whleNum%1000/100;//Remainder of division of 1000 then shift 2 left
        n10s=whleNum%100/10;   //Remainder of division of 100 then shift 1 left
        n1s=whleNum%10;        //Remainder of division by 10
        
        switch(n1000s){
            case 5:cout<<"Five Thousand ";
            case 4:cout<<"Four Thousand ";
            case 3:cout<<"Three Thousand ";
            case 2:cout<<"Two Thousand ";
            case 1:cout<<"One Thousand ";
        }
        cout<<(n100s==9?"Nine hundred ":
               n100s==8?"Eight hundred ":
               n100s==7?"Nine hundred ":
               n100s==6?"Six hundred ":
               n100s==5?"Five hundred ":
               n100s==4?"Four Hundred ":
               n100s==3?"Three hundred ":
               n100s==2?"Two hundred ":
               n100s==1?"One hundred ":"");
        
        cout<<(n10s==9?"Ninety ":
               n10s==8?"Eighty ":
               n10s==7?"Seventy ":
               n10s==6?"Sixty ":
               n10s==5?"Fifty ":
               n10s==4?"Forty ":
               n10s==3?"Thirty ":
               n10s==2?"Twenty ":
               n10s==1?"Ten ":
               n10s==1&&n1s==9?"Nineteen ":
               n10s==1&&n1s==8?"Eighteen ":
               n10s==1&&n1s==7?"Seventeen ":
               n10s==1&&n1s==6?"Sixteen ":
               n10s==1&&n1s==5?"Fifteen ":
               n10s==1&&n1s==4?"Fourteen ":
               n10s==1&&n1s==3?"Thirteen ":
               n10s==1&&n1s==2?"Twelve ":
               n10s==1&&n1s==1?"Eleven ":" ");
        
        cout<<(n1s==9?"Nine":
               n1s==8?"Eight":
               n1s==7?"Seven":
               n1s==6?"Six":
               n1s==5?"Five":
               n1s==4?"Four":
               n1s==3?"Three":
               n1s==2?"Two":
               n1s==1?"One":"");
        cout<<" dollars"<<endl;
     }else
         cout<<"Can't print amount too big"<<endl;
    //Signature line
    cout<<endl<<"__________________________________"<<endl;
}

float calcPay(EmpInfo &ary){
    float grsPay;
    if(ary.hours<=40){      //40 hours or less gets straight time
        grsPay=ary.payRate*ary.hours;
    }else if(ary.hours>40 && ary.hours<=60){ //between 40 and 60 hours gets double time
        int dTime=ary.hours-40; //double time 
        grsPay=(ary.payRate*2)*dTime+(ary.payRate*40);
    }else{
        int tTime=ary.hours-60; //triple time
        grsPay=(ary.payRate*3)*tTime+(ary.payRate*60);
    }
    return grsPay;
}

void getDat(EmpInfo &ary){
    //Fill static struct
    cout<<"Enter company name: ";
    cin.ignore();
    getline(cin, ary.company);
    cout<<"Enter employee's name: ";
    getline(cin, ary.name);
    cout<<"Enter employee's address: ";
    getline(cin, ary.address);
    cout<<"Enter number of hours worked: ";
    cin>>ary.hours;
    cout<<"Enter rate of pay: ";
    cin>>ary.payRate;
    ary.grosPay=calcPay(ary);
}