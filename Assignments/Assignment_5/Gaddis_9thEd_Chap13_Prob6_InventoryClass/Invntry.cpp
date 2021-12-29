/* 
 * File:   Inventory.h
 * Author: Arlene Sagaoinit
 * Created on November 6, 2021, 10:47 PM
 * Purpose: Inventory class member functions
 */

#include "Invntry.h"
#include <iostream>
using namespace std;

//Default constructor assigns member variables to 0
Invntry::Invntry(){
    itmNum=0;
    quant=0;
    cost=0.0;
};

//Second constructor accepts arguments for each member variable
//and uses mutator functions to assign members
Invntry::Invntry(int itemNum, int numItms, float price){
    setItmNum(itemNum);
    setQuant(numItms);
    setCost(price);
}

void Invntry::setItmNum(int num){
    if(num<0){  //Item number can't be negative
        cout<<"Invalid item number"<<endl;
    }else{
        itmNum=num;
    }
}

void Invntry::setQuant(int num){
    if(num<0){  //Quantity amount can't be negative
        cout<<"Invalid quantity number"<<endl;
    }else{
        quant=num;
    }
}
        
void Invntry::setCost(float val){
    if(val<0){  //Cost can't be negative
        cout<<"Invalid cost value"<<endl;
    }else{
        cost=val;
    }
}
