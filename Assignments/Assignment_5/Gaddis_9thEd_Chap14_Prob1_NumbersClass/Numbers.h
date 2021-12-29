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

#ifndef NUMBERS_H
#define NUMBERS_H

class Numbers{
    private:
        int num;
        void setNum(int);
    public:
        Numbers(int n)
         {setNum(n);}
        void print();
};


#endif /* NUMBERS_H */

