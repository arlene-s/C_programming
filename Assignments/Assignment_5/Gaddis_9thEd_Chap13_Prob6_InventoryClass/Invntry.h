/* 
 * File:   Inventory.h
 * Author: Arlene Sagaoinit
 * Created on November 6, 2021, 10:47 PM
 * Purpose: Inventory class specification
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Invntry{
    private:
        int itmNum;             //Item number
        int quant;              //Quantity of items
        float cost;             //Cost per number item
    public:
        Invntry();              //Default constructor assigns members to 0
        Invntry(int itemNum, int numItms, float price); //Second constructor
        void setItmNum(int);    //Set item number
        void setQuant(int);     //Set quantity number
        void setCost(float);    //Set cost per item
        int getItmNum()const    //Returns item number
            {return itmNum;}
        int getQuant()const     //Returns quantity 
            {return quant;}
        float getCost()const    //Returns cost per item
            {return cost;}
        float getTotCost()const //Calculates and returns total inventory cost
            {return getQuant()*getCost();}
};


#endif /* INVENTORY_H */

