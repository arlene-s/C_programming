/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on September 6, 2021, 3:43 PM
 * Purpose:  Report the number of rainy, cloudy, and sunny days
 *           for each month in a three month period, and the month with most
 *           number of rainy days
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <fstream>    //Read file 
#include <iomanip>    //setw()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables

//Math/Physics/Science/Conversions/Dimensions
const char COLS=30; //Number of days in each month

//Function Prototypes
int numMnth(char [][COLS], int, char); //searches array for specified character R,C,or S
                                       //and returns the amount of character in each month

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    const char rows = 3;  //Number of months
    char ary[rows][COLS]; //Array for each day of each month
    char temp;            //Read file and store in temp to be assigned to array
    char month;           //Month with most rainy days
    ifstream inFile;      //Input file
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    inFile.open("RainOrShine.txt"); //Open existing file with report
    
    if(inFile){
        for(int i=0;i<rows;i++){
            for(int j=0;j<COLS;j++){
                inFile>>ary[i][j];  //Read in each value in file and store in array
            }
        }
        inFile.close();
    }
    else
        cout<<"Error opening file"<<endl;
    
    //Display the results
    cout<<"Number of rainy, cloudy, sunny days in each month"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"\tRainy\tCloudy\tSunny"<<endl;
    
    cout<<"Month 1 "<<left<<setw(9)
        <<numMnth(ary,0,'R')<<setw(9) //numMnth(array, month to report, character to analyze)
        <<numMnth(ary,0,'C')<<setw(9)
        <<numMnth(ary,0,'S')<<endl;
    
    cout<<"Month 2 "<<setw(9)
        <<numMnth(ary,1,'R')<<setw(9)
        <<numMnth(ary,1,'C')<<setw(9)
        <<numMnth(ary,1,'S')<<endl;
    
    cout<<"Month 3 "<<setw(9)
        <<numMnth(ary,2,'R')<<setw(9)
        <<numMnth(ary,2,'C')<<setw(9)
        <<numMnth(ary,2,'S')<<endl;
    
    cout<<"Total   "<<setw(9)
        <<numMnth(ary,0,'R')+numMnth(ary,1,'R')+numMnth(ary,2,'R')<<setw(9)
        <<numMnth(ary,0,'C')+numMnth(ary,1,'C')+numMnth(ary,2,'C')<<setw(9)
        <<numMnth(ary,0,'S')+numMnth(ary,1,'S')+numMnth(ary,2,'S')<<endl;
    
    //Compare number of rainy days in each month
    month = numMnth(ary,0,'R')>numMnth(ary,1,'R')&&numMnth(ary,0,'R')>numMnth(ary,2,'R')?1:
            numMnth(ary,1,'R')>numMnth(ary,0,'R')&&numMnth(ary,1,'R')>numMnth(ary,2,'R')?2:3;

    cout<<endl<<"Month with most number of rainy days is month "<<static_cast<int>(month);
    return 0;
}

int numMnth(char a[][COLS],int month,char letter){
    int num=0; //Number of rainy, cloudy, or sunny days in month specified
    
    for(int i=0;i<COLS;i++) //Search array for R,C, or S and increment num
        a[month][i]==letter?num++:num;
    
    return num; //Return number of occurences in the month
}


