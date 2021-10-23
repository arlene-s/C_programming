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
#include "Array.h"
#include "Stats.h"
//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm6();
Customr *getDat(int &,int &);     //fill with customer info and return struct
void calcBal(Customr *,int,int);  //calculate the new balance
void print(Customr *,int,int);    //Print customer information
void destroy(Customr *);         
void getDat(EmpInfo &);           //Grabs input
float calcPay(EmpInfo &);         //Calculates gross pay
void print(EmpInfo);              //Print check
Array *fillAry(int,int);          //Fill an array and put into a structure
void prntAry(const Array *,int);  //Print the array 
int *copy(const int *,int);       //Copy the array
void mrkSort(int *,int);          //Sort an array
void prtStat(const Stats *);      //Print the structure
void rcvrMem(Array *);            //Recover memory from the Array Structure
void rcvrMem(Stats *);            //Recover memory from Statistics Structure
Stats *stat(const Array *);       //Find & store mean, median, & modes in structure
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm6();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='4');
    
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
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 6"<<endl<<endl;
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

//                         Problem 3
//Description: Mode Problem, modify stats function to find modes, frequency, 
//             median, and average
void prblm3(){
    cout<<"Problem 3"<<endl;
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
}

//                         Problem 4
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

//Prob 2
void print(EmpInfo ary){ 
    cout<<endl<<ary.address<<endl;
    cout<<"Pay to the"<<endl
        <<left<<setw(12)<<"Order of "<<setw(18)<<ary.name<<"$"<<ary.grosPay<<endl;
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

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size=0;
    int sum=0, compCnt=0, maxCnt=0, freq=0, nModes=0, index=0;
    
    //Calculate average
    for(int i=0; i<array->size;i++)
        sum+=array->data[i];            //Take the sum of the elements
    stats->avg=1.0f*sum/array->size;
    //Calculate median
    if(array->size%2==0)
        stats->median=(array->data[(array->size-1)/2]+array->data[(array->size)/2])/2.0f;
    else
        stats->median=array->data[array->size/2];
    
    //Calculate frequency and number of modes
    for(int i=0;i<array->size-1;i++){
        if(array->data[i]==array->data[i+1]){
            compCnt++;              //comparison count, increment when neighbor is equal
            if(compCnt>maxCnt){      
                maxCnt=compCnt;     //Store the max count
            }
            if(compCnt==maxCnt)     //Increment number of modes when max count reached
               nModes++;
        }else
            compCnt=0;              //Set compCnt back to 0 when neighbors aren't equal
    }
    stats->modFreq=maxCnt+1;
    if(nModes!=0){                  //If number of modes is 1 or greater
        stats->mode->size=nModes;   //Set mode size;
        stats->mode->data=new int[nModes]; //allocate memory to pointer
        for(int i=0; i<array->size-1; i++){
            if(array->data[i]==array->data[i+1]){
                compCnt++;
                if(compCnt==maxCnt){    //Store all values with the max count
                stats->mode->data[index]=array->data[i];
                index++;
                }
            }else
                compCnt=0;
        }
    }
    return stats;
}

