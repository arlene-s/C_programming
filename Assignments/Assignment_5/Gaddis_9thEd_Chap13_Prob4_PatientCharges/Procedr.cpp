/* 
 * File:   Procedure.h
 * Author: arlen
 *
 * Created on November 6, 2021, 7:03 PM
 */

#include "Procedure.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Procedr class constructor: assigns values to member variables
Procedr::Procedr(string prc, string d, string pra, int c){
    setPrc(prc);
    setDate(d);
    setPra(pra);
    setChrg(c);
}