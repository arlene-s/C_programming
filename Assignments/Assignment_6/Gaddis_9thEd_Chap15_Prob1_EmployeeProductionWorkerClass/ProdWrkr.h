/* 
 * File:   ProdWrkr.h
 * Author: Arlene Sagaoinit
 * Created on November 28, 2021, 8:34 PM
 * Purpose: Production worker class specification derived from base Employee class
 */

#ifndef PRODWRKR_H
#define PRODWRKR_H

#include "Employee.h"

class ProdWrkr:public Employee{
    private:
        int shift;
        float payRate;
    public:
        //Default constructor
        ProdWrkr();
        
        //Constructor to initialize members
        ProdWrkr(int,float);
        
        //Mutator
        void setWrkr(int,float);
        //Accessor
        int getShift(){return shift;}
        //Display worker's info
        void display();
};



#endif /* PRODWRKR_H */

