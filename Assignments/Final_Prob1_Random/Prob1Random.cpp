/* 
 * File:   Prob1Random.h
 * Author: Arlene Sagaoinit
 * Created on December 14, 2021, 1:05 PM
 * Purpose: Prob1Random class implementation
 */

#include "Prob1Random.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Prob1Random::Prob1Random(const char size, const char *array){
    nSet=size<2?2:size;
    set=new char[nSet];
    freq=new int[nSet];
    for(int i=0; i<nSet;i++){
        set[i]=array[i];
        freq[i]=0;
    }
    numRand=0;
}

Prob1Random::~Prob1Random(){
    delete []set;
    delete []freq;
}

void Prob1Random::randFromSet(){
    int randNum;
    randNum=set[rand()%nSet];
    numRand++;
    for(int i=0; i<nSet;i++){
        if(randNum==set[i]){
            freq[i]=freq[i]+1;
        }
    }
}

int *Prob1Random::getFreq() const{
    return freq;
}

char *Prob1Random::getSet() const{
    return set;
}

int Prob1Random::getNumRand() const{
    return numRand;
}

void Prob1Random::display(){
    for(int i=0; i<nSet;i++){
        cout<<static_cast<int>(set[i])<<" ";
    }
    cout<<endl;
    for(int i=0; i<nSet;i++)
    {
        cout<<freq[i]<<" ";
    }
}