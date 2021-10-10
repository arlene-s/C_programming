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

void getData(Weather [], int);  //read in data

int main(){
	//your code here
	const int SIZE=6;      //Size 12 for number of months in year
	Weather array[SIZE];    //Array of structures
        Months month;
	float yearRain;         //Takes the sum of total rainfall in the year
	float yearTemp;         //Takes the sum of the total average temperature in the year
	float avgRain;          //Averages the monthly rainfall
	float averTemp;         //Averages the monthly temperature
	int min=0, max=0;
	for(month=JANUARY;month<=JUNE;month=static_cast<Months>(month+1)){
            getData(array, month);
            
            if(min>array[month].lTemp){
                min=array[month].lTemp;     //Record min temperature
            }
            if(max<array[month].hTemp){
	        max=array[month].hTemp;     //Record max temperature
	    }
            
	    yearRain+=array[month].totRain; 
	    yearTemp+=(array[month].hTemp+array[month].lTemp)/2.0;
	}
        
	avgRain=yearRain/SIZE;  //Calculate average
	averTemp=yearTemp/SIZE;
        
        cout<<"Average monthly rainfall:"<<avgRain<<endl;
        cout<<"High Temp:"<<max<<endl;
        cout<<"Low Temp:"<<min<<endl;
        cout<<"Average Temp:"<<averTemp;
	return 0;
}

void getData(Weather a[], int indx){
    cout<<"Enter the total rainfall for the month:";
    cin>>a[indx].totRain;
    cout<<"Enter the high temp:";
    cin>>a[indx].hTemp;
    cout<<"Enter the low temp:";
    cin>>a[indx].lTemp;
}

