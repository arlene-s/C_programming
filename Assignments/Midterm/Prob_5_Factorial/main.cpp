/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on October 21, 2021, 10:28 AM
 * Purpose: Display results for all primitive data types signed and unsigned
 *          of the largest n where n!=factorial
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //setw()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
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
    return 0;
}



