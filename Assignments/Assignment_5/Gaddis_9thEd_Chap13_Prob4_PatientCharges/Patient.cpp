/* 
 * File:   Patient.h
 * Author: Arlene Sagaoinit
 * Created on November 1, 2021, 8:00 PM
 * Purpose: Member functions of patient class
 */

#include "Patient.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Patient class constructor: assigns values to member variables
Patient::Patient(string first,string midd,string last,string adrss, 
        string c,string s,string z,string pNum,string eName,
        string eNum){
    setFrst(first);
    setMidd(midd);
    setLast(last);
    setAdd(adrss);
    setCity(c);
    setSt(s);
    setZip(z);
    setPNum(pNum);
    setENam(eName);
    setENum(eNum);
}