/* 
 * File: main.cpp
 * Author: Arlene Sagaoinit
 * Created on October 5 2021 8:30pm
 * Purpose:  Use enumerated data type to repesent the months in the year
 */
 
#include <iostream>
#include <iomanip>
using namespace std;

enum Months {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER}; 

struct Weather{
    string month;       //Month in the year
    float totRain;        //Total rainfall
    int hTemp;          //Highest temperature in the month ->degrees fahrenheit
    int lTemp;          //Lowest temperature in the month ->degrees fahrenheit
    float avgTemp;      //Average temperature of the month ->degrees fahrenheit
};

void getData(Weather [], int);  //Read in data

int main(){
    //Declare variables
    const int SIZE=12;      
    Weather array[SIZE];    //Array of structures
    Months month;
    float yearRain;         //Takes the sum of total rainfall in the year
    float yearTemp;         //Takes the sum of the total average temperature in the year
    float avgRain;          //Averages the monthly rainfall
    float averTemp;         //Averages the monthly temperature

    //Initialize variables
    
    //Process or map Inputs to Outputs
    for(month=JANUARY;month<=DECEMBER;month=static_cast<Months>(month+1)){
    getData(array, month);
        yearRain+=array[month].totRain; 
        yearTemp+=array[month].avgTemp;
    }

    int min=array[0].lTemp;
    int max=array[0].hTemp;
    for(month=FEBRUARY;month<=DECEMBER;month=static_cast<Months>(month+1)){
    if(min>array[month].lTemp){
        min=array[month].lTemp;     //Record min temperature
    }
    if(max<array[month].hTemp){
        max=array[month].hTemp;     //Record min temperature
    }
    }
    avgRain=yearRain/SIZE;  //Calculate average
    averTemp=yearTemp/SIZE;

    //Outputs
    cout<<"Average monthly rainfall:"<<avgRain<<endl;
    cout<<"High Temp:"<<max<<endl;
    cout<<"Low Temp:"<<min<<endl;
    cout<<"Average Temp:"<<averTemp;
    //Exit
    return 0;
}

void getData(Weather a[], int indx){
    cout<<"Enter the total rainfall for the month:"<<endl;
    cin>>a[indx].totRain;
    cout<<"Enter the high temp:"<<endl;
    cin>>a[indx].hTemp;
    cout<<"Enter the low temp:"<<endl;
    cin>>a[indx].lTemp;
    
    a[indx].avgTemp=((a[indx].hTemp)+(a[indx].lTemp))/2.0f;
}
