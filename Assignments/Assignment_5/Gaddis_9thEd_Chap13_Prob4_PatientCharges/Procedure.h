/* 
 * File:   Procedure.h
 * Author: Arlene Sagaoinit
 * Created on November 6, 2021, 7:03 PM
 * Purpose: Procedure class specification
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Procedr{
    private:
        string prcedur;     //Procedure name
        string date;        //Todays date
        string pract;       //Practitioner name
        int charge;         //charge amount
    public:
        //Constructor to assign values to member variables
        Procedr(string prc, string d, string pra, int c);
        void setPrc(string prc)     //Set procedure name
            {prcedur=prc;}
        void setDate(string d)      //Set todays date
            {date=d;}
        void setPra(string pra)     //Set practitioners name
            {pract=pra;}    
        void setChrg(int c)         //Set charge amount
            {charge=c;} 
        string getPrc()             //Return procedure name
            {return prcedur;}
        string getDate()            //Return todays date
            {return date;}
        string getPra()             //Return practitioner name
            {return pract;}
        int getChrg()               //Return charge amount
            {return charge;}
};


#endif /* PROCEDURE_H */

