/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 1, 2021, 7:59 PM
 * Purpose: Store patient and medical procedure information and display
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Patient.h"
#include "Procedure.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void patInfo(Patient);
void prcInfo(Procedr);
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int totChrg=0;      //Holds total procedure charge

    //Initialize variables here
    //Create patient instance with initialized values
    Patient patient("Tokyo","R","Ghoul","1400 Alessandro Blvd","Moreno","CA",
                    "92566","8082569047","Brenda","8084812067");
    
    //Create procedr instances with initialized values
    Procedr proced1("Physical exam","Nov 6 2021","Dr. Irvine",250);
    Procedr proced2("X-ray","Nov 6 2021","Dr. Jamison",500);
    Procedr proced3("Blood test","Nov 6 2021","Dr. Smith",200);
    
    //Map inputs to outputs here, i.e. the process
    //Calculate total charge
    totChrg=proced1.getChrg()+proced2.getChrg()+proced3.getChrg();
    
    //Display the results
    patInfo(patient);
    prcInfo(proced1);
    prcInfo(proced2);
    prcInfo(proced3);
    cout<<"Total charge: $"<<totChrg<<endl;
    
    return 0;
}

void patInfo(Patient pat){
    cout<<"Name: "<<pat.getFrst()<<" "<<pat.getMidd()<<" "<<pat.getLast()<<endl;
    cout<<"Address: "<<pat.getAdd()<<endl<<pat.getCity()<<", "<<pat.getSt()<<", "
                     <<pat.getZip()<<endl;
    cout<<"Phone number: "<<pat.getPNum()<<endl;
    cout<<"Emergency contact: "<<pat.getENam()<<endl;
    cout<<"Emergency contact number: "<<pat.getENum()<<endl;
}

void prcInfo(Procedr proc){
    cout<<"Procedure name: "<<proc.getPrc()<<endl;
    cout<<"Today's Date: "<<proc.getDate()<<endl;
    cout<<"Practitioner: "<<proc.getPra()<<endl;
    cout<<"Charge: $"<<proc.getChrg()<<endl;
}
