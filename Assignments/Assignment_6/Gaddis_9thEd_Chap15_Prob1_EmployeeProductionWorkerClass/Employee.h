/* 
 * File:   Employee.h
 * Author: Arlene Sagaoinit
 * Created on November 28, 2021, 8:17 PM
 * Purpose: Employee class specification
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee{
    private:
        string empName;     //Employee's name
        string empNum;      //Employee's number
        string hireDate;    //Employee's hire date
    public:
        //Default constructor
        Employee();
        
        //Constructor to initialize values
        Employee(string,string,string);
        
        //Mutator
        void setEmp(string,string,string);
        
        //Accessors
        string getName(){return empName;}
        string getNum(){return empNum;}
        string getDate(){return hireDate;}
        
        //Display employee's information
        void display();
};



#endif /* EMPLOYEE_H */

