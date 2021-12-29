/* 
 * File:   Employee.h
 * Author: Arlene Sagaoinit
 * Created on November 28, 2021, 8:17 PM
 * Purpose: Employee class member functions
 */

#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(){
    setEmp("","","");      //Initialize employee information to empty strings
}

//Initialize employee information
Employee::Employee(string name, string num, string date){
    setEmp(name,num,date);
}

//Assign info to member variables
void Employee::setEmp(string name, string num, string date){
    empName=name;
    empNum=num;
    hireDate=date;
}

void Employee::display(){
    cout<<"Employee name: "<<empName<<endl;
    cout<<"Employee number: "<<empNum<<endl;
    cout<<"Employee hire date: "<<hireDate<<endl;
}

