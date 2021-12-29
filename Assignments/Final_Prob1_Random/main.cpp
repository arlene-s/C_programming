/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on December 14, 2021, 1:05 PM
 * Purpose: Get a sequence of numbers from a set and record the frequencies 
 *          of each number pulled, display frequency array
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Prob1Random.h"

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    char n=5;
    char rndseq[]={29,34,57,89,126};
    int ntimes=100000;
    Prob1Random a(n, rndseq);
    for(int i=1; i<=ntimes;i++){
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0; i<n; i++){
        cout<<static_cast<int>(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<endl<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    
    return 0;
}

