/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Purpose: Display results of conversions from decimal to NASA format
 * Created on October 22, 2021, 9:16 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    cout<<left;
    cout<<"Problem a1): "<<endl;
    cout<<setw(16)<<"Decimal"<<setw(16)<<"Binary"<<setw(16)<<"Octal"
        <<setw(16)<<"Hex"<<setw(16)<<"NASA format"<<endl;
    cout<<setw(16)<<"49.1875"<<setw(16)<<"110001.0011"<<setw(16)<<"61.14"
        <<setw(16)<<"31.3"<<setw(16)<<"62600006"<<endl
        <<setw(16)<<"3.07421875"<<setw(16)<<"11.00010011"<<setw(16)<<"3.046"
        <<setw(16)<<"3.13"<<setw(16)<<"62600002"<<endl
        <<setw(16)<<"0.2"<<setw(16)<<"0.R0011"<<setw(16)<<"0.R1463"
        <<setw(16)<<"0.R3"<<setw(16)<<"666666FF"<<endl<<endl;
    //Numbers after R are repeating
    
    cout<<"Problem a2): "<<endl;
    cout<<setw(16)<<"Decimal"<<setw(16)<<"Binary"<<setw(16)<<"Octal"
        <<setw(16)<<"Hex"<<setw(16)<<"NASA format"<<endl
        <<setw(16)<<"-49.1875"<<setw(16)<<"1110.110"<<setw(16)<<"-61.14"
        <<setw(16)<<"-31.3"<<setw(16)<<"76800004"<<endl
        <<setw(16)<<"-3.07421875"<<setw(16)<<"0.11101101"<<setw(16)<<"-3.046"
        <<setw(16)<<"-3.13"<<setw(16)<<"76800000"<<endl
        <<setw(16)<<"-0.2"<<setw(16)<<"1.R1100"<<setw(16)<<"-0.1463"
        <<setw(16)<<"-0.3"<<setw(16)<<"73333401"<<endl<<endl;
    
    cout<<"Problem a3): "<<endl;
    cout<<setw(16)<<"NASA format"<<setw(16)<<"Binary"<<setw(16)<<"Octal"
        <<setw(16)<<"Hex"<<setw(16)<<"Decimal"<<endl
        <<setw(16)<<"69999902"<<setw(16)<<"11.0R1001"<<setw(16)<<"3.2R3146"
        <<setw(16)<<"3.4RC"<<setw(16)<<"3.3"<<endl
        <<setw(16)<<"69999903"<<setw(16)<<"110.R1001"<<setw(16)<<"6.R4641"
        <<setw(16)<<"6.R9"<<setw(16)<<"6.6"<<endl
        <<setw(16)<<"96667FF"<<setw(16)<<"1.0110R1001"<<setw(16)<<"-1.32R31468"
        <<setw(16)<<"-1.6R9"<<setw(16)<<"-1.4125"<<endl;
    return 0;
}

