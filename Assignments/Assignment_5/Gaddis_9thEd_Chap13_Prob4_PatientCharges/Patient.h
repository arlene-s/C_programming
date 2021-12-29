/* 
 * File:   Patient.h
 * Author: Arlene Sagaoinit
 * Created on November 1, 2021, 8:00 PM
 * Purpose: Patient class specification
 */

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Patient{
    private:
        string fName;       //First name of patient
        string mName;       //Middle name
        string lName;       //Last name
        string address;     //Patient street address
        string city;    
        string state;
        string zip;
        string phoNum;      //Patient phone number
        string emName;      //Emergency contact name
        string emNum;       //Phone number of emergency contact
    public:
        //Initialize values with patient constructor
        Patient(string first,string midd,string last,string adrss, 
                string c,string s,string z,string pNum,string eName,
                string eNum);
        void setFrst(string first)    //Set first name
            {fName=first;}
        void setMidd(string midd)     //Set middle name
            {mName=midd;}
        void setLast(string last)     //Set last name
            {lName=last;}
        void setAdd(string adrss)     //Set address
            {address=adrss;}
        void setCity(string c)        //Set city name
            {city=c;}
        void setSt(string s)          //Set state
            {state=s;}
        void setZip(string z)         //Set zip code
            {zip=z;}
        void setPNum(string pNum)     //Set phone number
            {phoNum=pNum;}
        void setENam(string eName)    //Set emergency contact name
            {emName=eName;}
        void setENum(string eNum)     //Set emergency contact phone number
            {emNum=eNum;}
        //Return function for each member variable
        string getFrst()
            {return fName;}
        string getMidd()
            {return mName;}
        string getLast()
            {return lName;}
        string getAdd()
            {return address;}
        string getCity()
            {return city;}
        string getSt()
            {return state;}
        string getZip()
            {return zip;}
        string getPNum()
            {return phoNum;}
        string getENam()
            {return emName;}
        string getENum()
            {return emNum;}
};


#endif /* PATIENT_H */

