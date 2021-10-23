/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
/* 
 * File:   Customr.h
 * Author: Arlene Sagaoinit
 * Purpose: Problem 1 structure containing customers bank information
 * Created on October 22, 2021, 7:09 PM
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

