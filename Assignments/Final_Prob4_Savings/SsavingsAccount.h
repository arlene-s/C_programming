/* 
 * File:   SsavingsAccount.h
 * Author: Arlene Sagaoinit
 * Created on December 17, 2021, 4:37 PM
 * Purpose: SavingsAccount class specification
 */

#ifndef SSAVINGSACCOUNT_H
#define SSAVINGSACCOUNT_H

class SavingsAccount{
    private:
        void Withdraw(float); //Utility Procedure
        void Deposit(float);//Utility Procedure
        float Balance; //Property
        int FreqWithDraw; //Property
        int FreqDeposit; //Property
    public:
        SavingsAccount(float); //Constructor
        void Transaction(float); //Procedure
        float Total(float=0,int=0); //Savings Procedure
        float TotalRecursive(float=0,int=0);
        void toString(); //Output Properties
};



#endif /* SSAVINGSACCOUNT_H */

