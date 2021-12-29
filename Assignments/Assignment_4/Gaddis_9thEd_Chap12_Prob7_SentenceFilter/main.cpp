/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on December 12, 2021, 5:12 PM
 * Purpose: Open two files, read from one file and convert each letter in 
 *          sentence to lowercase except the first letter, and store in 
 *          second file
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <fstream>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    fstream inFile, outFile;
    char letter;
    string sent;
    
    inFile.open("First File.txt", ios::in);
    outFile.open("Second File.txt",ios::out);
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    if(inFile){
        while(inFile){
            inFile.get(letter);
            outFile.put(toupper(letter));
            while(letter!='.'){
                outFile.put(tolower(letter));
                inFile.get(letter);
            }
        }
        inFile.close();
        outFile.close();
    }else{
        cout<<"Error opening file"<<endl;
    }
    
    inFile.close();
    outFile.close();
    
    //Display the results
    

    return 0;
}