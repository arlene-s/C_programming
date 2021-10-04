/* 
 * Author: Arlene Sagaoinit
 * Date: September 13 2021
 * Purpose: More formatting of inputs 
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    float num1, num2, num3, num4;
    
    //Initialize or input data here
    cin>>num1>>num2>>num3>>num4;
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cout<<setw(9)<<num1<<setw(10)<<setprecision(2)<<showpoint<<num1<<setw(10)<<setprecision(3)<<num1<<endl;
    cout<<setw(9)<<noshowpoint<<setprecision(1)<<num2<<setw(10)<<showpoint<<setprecision(2)<<num2<<setw(10)<<setprecision(3)<<num2<<endl;
    cout<<setw(9)<<noshowpoint<<setprecision(1)<<num3<<setw(10)<<showpoint<<setprecision(2)<<num3<<setw(10)<<setprecision(3)<<num3<<endl;
    cout<<setw(9)<<noshowpoint<<setprecision(1)<<num4<<setw(10)<<showpoint<<setprecision(2)<<num4<<setw(10)<<setprecision(3)<<num4;
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}