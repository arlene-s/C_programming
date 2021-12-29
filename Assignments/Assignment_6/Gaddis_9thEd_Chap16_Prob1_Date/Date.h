/* 
 * File:   Date.h
 * Author: Arlene Sagaoinit
 * Created on November 29, 2021, 7:42 PM
 * Purpose: Date class chapter 13 problem 1 specification modified to include exceptions
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{
    private:
        int day;    
        int month;
        int year;
    public:
        //Exception class for day
        class InvalidDay{
            private:
                int invalidDay;         //Holds invalid value
            public:
                InvalidDay(int day)
                    {invalidDay=day;}
                int getInvalid()
                    {return invalidDay;}
        };
        //Exception class for month
        class InvalidMnth{
            private:
                int invalidMnth;
            public:
                InvalidMnth(int mnth)
                    {invalidMnth=mnth;}
                int getInvalid()
                    {return invalidMnth;}
        };
        void setDay(int);       //Gives day variable a value
        void setMnth(int);      //Gives month variable a value
        void setYear(int);      //Gives year variable a value
        int getDay()const;      //Returns value of day
        int getMnth()const;     //Returns value of month
        int getYear()const;     //Returns value of year
        string strMnth();  //Returns string equivalent of month value
};

#endif /* DATE_H */

