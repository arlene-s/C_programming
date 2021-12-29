/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on December 16, 2021, 11:21 PM
 * Purpose: Create an augmented array using the sum of each row and column
 *          read table from file
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

#include "Prob3Inherited.h"
#include "Prob3Table.h"

int main(int argc, char** argv) {
    
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

