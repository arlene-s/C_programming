/* 
 * File:   SsavingsAccount.h
 * Author: Arlene Sagaoinit
 * Created on December 17, 2021, 4:37 PM
 * Purpose: SavingsAccount class implementation
 */

#include "SsavingsAccount.h"
#include <iostream>
#include <cmath> //abs()
using namespace std;

SavingsAccount::SavingsAccount(float bal){ //Constructor
    Balance=bal>0?bal:0;
    FreqWithDraw=0;
    FreqDeposit=0;
}

void SavingsAccount::Withdraw(float draw){ //Utility Procedure
    if(Balance-abs(draw)<0){
        cout<<"Amount exceeds balance, cannot withdraw"<<endl;
    }else{
        Balance-=abs(draw);
        FreqWithDraw++;
    }
}

void SavingsAccount::Deposit(float dep){ //Utility Procedure
    Balance+=dep;
    FreqDeposit++;
}

void SavingsAccount::Transaction(float tran){ //Procedure
    if(tran>=0)Deposit(tran);
    else Withdraw(tran);
}

float SavingsAccount::Total(float savint,int time){ //Savings Procedure
    for(int i=1;i<=time;i++){
        Balance*=(1+savint);
    }
    return Balance;
}

float SavingsAccount::TotalRecursive(float savint,int time){
    if(time<=0)return Balance;
    return TotalRecursive(savint,time-1)*(1+savint);
}

void SavingsAccount::toString(){ //Output Properties
    cout<<"Balance="<<Balance<<endl;
    cout<<"WithDraws="<<FreqWithDraw<<endl;
    cout<<"Deposits="<<FreqDeposit<<endl;
}