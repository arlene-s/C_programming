/* 
 * File:   Numbers.h
 * Author: Arlene Sagaoinit
 * Created on November 15, 2021, 8:45 PM
 * Purpose: Numbers class specification
 * Includes: member variable to hold number being translated
 *           private mutator function to assign value to variable
 *           default constructor that takes an integer argument 
 *           void print function to print number in english description
 */


#include "Numbers.h"
#include <iostream>
using namespace std;

void Numbers::setNum(int n){
    if(n<0||n>9999){
        cout<<"Number not in range specified"<<endl;
    }else{
        num=n;
    }
}

void Numbers::print(){
    //Array to hold 0-20
    string lessThan20[]={"zero","one","two","three","four","five","six","seven",
                         "eight","nine","ten","eleven","twelve","thirteen","fourteen",
                         "fifteen","sixteen","seventeen","eighteen","nineteen"};
    //Array to hold 10-19
    string tens[]={"zero","ten","twenty","thirty","fourty","fifty","sixty","seventy",
                   "eigthy","ninety",};
    string hund="hundred";
    string thou="thousand";

    if(num==0)cout<<lessThan20[num];
    int n=num/1000;
    if(n>0)cout<<lessThan20[n]<<" "<<thou<<" ";
    num=num%1000;
    n=num/100;
    if(n>0)cout<<lessThan20[n]<<" "<<hund<<" ";
    num=num%100;
    n=num/10;
    if(n>0)cout<<tens[n]<<" ";
    num=num%10;
    n=num;
    if(n>0){cout<<lessThan20[n];}
}

