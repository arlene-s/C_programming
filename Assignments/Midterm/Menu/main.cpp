/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Purpose:  Menu using Functions
 */

//System Libraries
#include <iostream>
#include <iomanip>      //setw()
using namespace std;

//User Libraries
#include "Customr.h"    //Customer bank info struct
#include "EmpInfo.h"
//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm5();
void prblm6();
Customr *getDat(int &,int &);     //fill with customer info and return struct
void calcBal(Customr *,int,int);  //calculate the new balance
void print(Customr *,int,int);    //Print customer information
void destroy(Customr *);         
void getDat(EmpInfo &);           //Grabs input
float calcPay(EmpInfo &);         //Calculates gross pay
void print(EmpInfo);              //Print check
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    bool quit=false;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            default: {quit=true;cout<<"Exiting Menu"<<endl;}
        }
    }while(quit==false);
    
    //Exit stage right!
    return 0;
}

//                         Menu
//Description: Displays a prompt for user to print a problem of their choice
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl<<endl;
}

//                         Problem 1
//Description: Store customer's bank information and calculate overdrawn amount
//Allocate a struct,allocate both checks and deposits array, print info
void prblm1(){
    cout<<"Problem 1"<<endl;
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
}

//                         Problem 2
//Description: Store employee information, pay rate, hours worked, and calculate gross pay
//Allocate array of structures, fill struct and send to each element of array
void prblm2(){
    cout<<"Problem 2"<<endl;
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
}

//                          Problem 5
//Description: Displays results of the largest n where n!=factorial
void prblm5(){
    cout<<"Problem 5"<<endl;
    //Display the results
    cout<<"Largest n for all signed and unsigned primitive data types"<<endl;
    cout<<"____________________________________________"<<endl;
    cout<<setw(21)<<"n"<<endl
        <<setw(19)<<"Signed"<<setw(11)<<"Unsigned"<<left<<endl
        <<setw(15)<<"char"<<setw(10)<<"5"<<"5"<<endl
        <<setw(15)<<"short"<<setw(10)<<"7"<<"8"<<endl
        <<setw(15)<<"int"<<setw(10)<<"12"<<"12"<<endl
        <<setw(15)<<"long"<<setw(10)<<"20"<<"20"<<endl
        <<setw(15)<<"long long"<<setw(10)<<"20"<<"20"<<endl
        <<setw(15)<<"float"<<setw(10)<<"34"<<" "<<endl
        <<setw(15)<<"double"<<setw(10)<<"170"<<" "<<endl
        <<setw(15)<<"long double"<<setw(10)<<"1754"<<" "<<endl;
}

//                         Problem 6
//Description: cout function for NASA format conversion problem
//Displays results
void prblm6(){
    cout<<"problem 6"<<endl;
    cout<<left;
    cout<<"Problem a1): "<<endl;
    cout<<setw(16)<<"Decimal"<<setw(16)<<"Binary"<<setw(16)<<"Octal"
        <<setw(16)<<"Hex"<<setw(16)<<"NASA format"<<endl;
    cout<<setw(16)<<"49.1875"<<setw(16)<<"110001.0011"<<setw(16)<<"61.14"
        <<setw(16)<<"31.3"<<setw(16)<<"62600006"<<endl
        <<setw(16)<<"3.07421875"<<setw(16)<<"11.00010011"<<setw(16)<<"3.046"
        <<setw(16)<<"3.13"<<setw(16)<<"62600002"<<endl
        <<setw(16)<<"0.2"<<setw(16)<<"0.R0011"<<setw(16)<<"0.R1463"
        <<setw(16)<<"0.R3"<<setw(16)<<"666666FF"<<endl<<endl;
    //Numbers after R are repeating
    
    cout<<"Problem a2): "<<endl;
    cout<<setw(16)<<"Decimal"<<setw(16)<<"Binary"<<setw(16)<<"Octal"
        <<setw(16)<<"Hex"<<setw(16)<<"NASA format"<<endl
        <<setw(16)<<"-49.1875"<<setw(16)<<"1110.110"<<setw(16)<<"-61.14"
        <<setw(16)<<"-31.3"<<setw(16)<<"76800004"<<endl
        <<setw(16)<<"-3.07421875"<<setw(16)<<"0.11101101"<<setw(16)<<"-3.046"
        <<setw(16)<<"-3.13"<<setw(16)<<"76800000"<<endl
        <<setw(16)<<"-0.2"<<setw(16)<<"1.R1100"<<setw(16)<<"-0.1463"
        <<setw(16)<<"-0.3"<<setw(16)<<"73333401"<<endl<<endl;
    
    cout<<"Problem a3): "<<endl;
    cout<<setw(16)<<"NASA format"<<setw(16)<<"Binary"<<setw(16)<<"Octal"
        <<setw(16)<<"Hex"<<setw(16)<<"Decimal"<<endl
        <<setw(16)<<"69999902"<<setw(16)<<"11.0R1001"<<setw(16)<<"3.2R3146"
        <<setw(16)<<"3.4RC"<<setw(16)<<"3.3"<<endl
        <<setw(16)<<"69999903"<<setw(16)<<"110.R1001"<<setw(16)<<"6.R4641"
        <<setw(16)<<"6.R9"<<setw(16)<<"6.6"<<endl
        <<setw(16)<<"96667FF"<<setw(16)<<"1.0110R1001"<<setw(16)<<"-1.32R31468"
        <<setw(16)<<"-1.6R9"<<setw(16)<<"-1.4125"<<endl;
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
//Prob 1 functions
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
    cout<<left<<endl;
    cout<<setw(20)<<"Account number: "<<record->accNum<<endl;
    cout<<setw(20)<<"Name: "<<record->name<<endl;
    cout<<setw(20)<<"Address: "<<record->address<<endl;
    cout<<setw(20)<<"Beginning Balance: "<<"$"<<record->begBal<<endl;
    cout<<setw(20)<<"Checks: ";
    for(int i=0; i<chcks; i++)
        cout<<"$"<<record->checks[i]<<" ";
    cout<<endl;
    cout<<setw(20)<<"Deposits: ";
    for(int i=0; i<dpsits; i++)
        cout<<"$"<<record->dposits[i]<<" ";
}

//Prob 2 functions
void print(EmpInfo ary){ 
    cout<<endl<<ary.address<<endl;
    cout<<"Pay to the"<<endl
        <<left<<setw(12)<<"Order of "<<setw(18)<<ary.name<<"$"<<ary.grosPay<<endl;
    //Convert the amount into english words
    int whleNum=ary.grosPay;   //Whole numberS
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
               n100s==7?"Seven hundred ":
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
        
        cout<<(n1s==9?"Nine ":
               n1s==8?"Eight ":
               n1s==7?"Seven ":
               n1s==6?"Six ":
               n1s==5?"Five ":
               n1s==4?"Four ":
               n1s==3?"Three ":
               n1s==2?"Two ":
               n1s==1?"One ":"");
        cout<<"dollars"<<endl;
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