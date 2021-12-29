/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 29, 2021, 9:50 PM
 * Purpose: Create templates for the min and max function. Min function should 
 *          accept two values and return the smallest, max function should accept
 *          two values and return the largest
 */

#include <iostream>
using namespace std;

//Function prototypes
template <class T>
T min(T &x, T &y){
    return (x>y?y:x);   //Return min
}
template <class T>
T max(T &x, T &y){
    return (x>y?x:y);   //Return max
}

int main(int argc, char** argv) {
    //Declare variables
    int num,val;
    
    //Map inputs to outputs
    cout<<"Enter two values: ";
    cin>>num>>val;
    
    //Display results
    cout<<max(num,val)<<" is greater than "<<min(num,val)<<endl;

    return 0;
}

