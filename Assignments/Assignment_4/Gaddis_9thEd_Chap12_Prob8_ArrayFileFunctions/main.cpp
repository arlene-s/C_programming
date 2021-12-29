/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on December 9, 2021 9:24PM
 * Purpose: Create two functions
 *          arrayToFile -> write array contents to binary file
 *          fileToArray -> read from binary file to array
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <fstream>
#include <ctime>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void arrayToFile(fstream &,int *,int);
void fileToArray(fstream &,int *,int);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    fstream file;
    int size=10;
    int *array=new int[size];
    int *arry=new int[size];
    
    //Initialize variables here
    for(int i=0; i<size;i++){
        array[i]=rand()%51;
    }
    for(int i=0; i<size;i++){
        cout<<array[i]<<" ";
    }
    
    //Map inputs to outputs here, i.e. the process
    arrayToFile(file, array, size);
    fileToArray(file, arry, size);
    
    //Display the results
    cout<<endl;
    for(int i=0; i<size;i++){
        cout<<arry[i]<<" ";
    }
    
    //Delete memory
    delete []array;
    delete []arry;

    return 0;
}

void arrayToFile(fstream &outFile,int *arr, int n){
    outFile.open("array.txt", ios::out|ios::binary);
    outFile.write(reinterpret_cast<char*>(arr),sizeof(arr));
    outFile.close();
}

void fileToArray(fstream &inFile,int *arr,int n){
    inFile.open("array.txt",ios::in|ios::binary);
    if(inFile){
        inFile.read(reinterpret_cast<char*>(arr),sizeof(arr));
        inFile.close();
    }else{
        cout<<"Error opening file"<<endl;
    }
}