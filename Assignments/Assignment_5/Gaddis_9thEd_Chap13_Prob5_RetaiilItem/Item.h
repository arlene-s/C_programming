/* 
 * File:   Item.h
 * Author: Arlene Sagaoinit
 * Created on November 6, 2021, 8:51 PM
 * Purpose: Retail item class specification
 */

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item{
    private:
        string desc;     //Description of item
        int units;       //Number of units in inventory
        float price;     //Price of item
    public:
        Item(string d, int u, float p);     //Constructor
        void setDesc(string d);             //Set Description of item
        void setUnits(int u);               //Set amount of item in inventory
        void setPrice(float p);             //Set price amount of item
        string getDesc()                    //Return description of item
            {return desc;}  
        int getUnits()                      //Return units of item
            {return units;}
        float getPrice()                    //Price of item
            {return price;}
};




#endif /* ITEM_H */

