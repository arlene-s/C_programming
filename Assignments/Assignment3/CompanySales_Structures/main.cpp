/* 
 * File:   
 * Author: Arlene Sagaoinit
 * Created on October 3, 2021 7:10pm
 * Purpose: To store sales data on a company division
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct Divsn{ //Struct with each quarter sales
    float frstQ;
    float secQ;
    float thrdQ;
    float frthQ;
    float totSales;
    float avgSales;
};

void getData(Divsn&);  //Get data, pass by reference to modify struct 
void calcData(Divsn&); //Calculate total and average sales, pass by reference to modify struct 

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    
    //Initialize Variables
    //Create a variable for each division
    Divsn east;
    Divsn west;
    Divsn north;
    Divsn south;
    
    //Process or map Inputs to Outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    
    //Display output for each division, its sales, total, and average
    cout<<"North"<<endl;
    getData(north);
    calcData(north);
    cout<<endl;
    
    cout<<"West"<<endl;
    getData(west);
    calcData(west);
    cout<<endl;
    
    cout<<"East"<<endl;
    getData(east);
    calcData(east);
    cout<<endl;
    
    cout<<"South"<<endl;
    getData(south);
    calcData(south);

    //Exit stage right!
    return 0;
}
void getData(Divsn &n){
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>n.frstQ;
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>n.secQ;
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>n.thrdQ;
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>n.frthQ;
}

void calcData(Divsn &n){
    //Calculate total sales by taking sum of sales of all quarters
    n.totSales=n.frstQ+n.secQ+n.thrdQ+n.frthQ;
    //Calculate average sales by taking the total of all sales and dividing by number of divisions
    n.avgSales=n.totSales/4;
    
    cout<<"Total Annual sales:$"<<n.totSales<<endl;
    cout<<"Average Quarterly Sales:$"<<n.avgSales;
}
