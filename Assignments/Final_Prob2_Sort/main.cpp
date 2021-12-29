/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on December 14, 2021, 2:46 PM
 * Purpose: Sort a 2dimensional array as a 1 dimensional, use index database sort
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

#include "Prob2Sort.h"

int main(int argc, char** argv) {
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<char> rc;
    bool ascending=false;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*15];  //10 rows 15 columns from file
    char letter;
    int i=0;
    while(infile>>letter){  //Read in file and store into char array
        if(letter!='\n')ch2[i]=letter;
        i++;
    }
    infile.close();
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++)   //Output file contents
            cout<<ch2[i*15+j];
        cout<<endl;
    }
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    int *zc=rc.sortArray(ch2,10,15,column,ascending);   //Return the index array
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            cout<<ch2[zc[i*15+j]];  //Use index array to output sorted 2d array
        }
        cout<<endl;
    }
    delete []ch2;

    return 0;
}

