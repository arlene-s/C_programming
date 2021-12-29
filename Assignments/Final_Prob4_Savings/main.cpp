/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on December 17, 2021, 4:35 PM
 * Purpose: Calculate savings amount with interest rate and time
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "SsavingsAccount.h"

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    SavingsAccount mine(-300);
    
    for(int i=1;i<=10;i++){
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    
    mine.toString();
    
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
    return 0;
}

