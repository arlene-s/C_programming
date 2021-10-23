/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Customr.h
 * Author: Arlene Sagaoinit
 * Purpose: Customer bank information structure
 * Created on October 18, 2021, 8:42 PM
 */

#ifndef CUSTOMR_H
#define CUSTOMR_H

struct Customr{             //Struct of customers information
    unsigned int accNum;    //Account number
    string name;            //Customer name
    string address;         //Customer address
    float begBal;           //Balance at beginning of month
    float *checks;          //Checks customer wrote in the month
    float *dposits;         //Deposits credited to customer in the month
};

#endif /* CUSTOMR_H */

