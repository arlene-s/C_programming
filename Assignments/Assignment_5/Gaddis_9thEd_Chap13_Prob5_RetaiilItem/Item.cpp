/* 
 * File:   Item.h
 * Author: Arlene Sagaoinit
 * Created on November 6, 2021, 8:51 PM
 * Purpose: Retail item class member functions
 */

#include "Item.h"
#include <iostream>
using namespace std;

void Item::setDesc(string d){
    desc=d;
}

void Item::setUnits(int u){
    if(u<0){        //Item amount can't be negative
        cout<<"Invalid amount of units"<<endl;
    }else{
        units=u;
    }
}

void Item::setPrice(float p){
    if(p<0){        //Price can't be negative
        cout<<"Invalid price value"<<endl;
    }else{
        price=p;
    }
}

Item::Item(string d, int u, float p){
    setDesc(d);
    setUnits(u);
    setPrice(p);
}