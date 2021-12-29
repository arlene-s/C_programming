/* 
 * File:   Scores.h
 * Author: Arlene Sagaoinit
 * Created on November 6, 2021, 11:57 PM
 * Purpose: Test Scores class specification
 */

#include "Scores.h"
#include <iostream>
using namespace std;

Scores::Scores(int s1,int s2,int s3){
    setSc1(s1);
    setSc2(s2);
    setSc3(s3);
}

void Scores::setSc1(int s1){
    if(s1<0){
        cout<<"Invalid score input"<<endl;
    }else{
        score1=s1;
    }
}

void Scores::setSc2(int s2){
    if(s2<0){
        cout<<"Invalid score input"<<endl;
    }else{
        score2=s2;
    }
}

void Scores::setSc3(int s3){
    if(s3<0){
        cout<<"Invalid score input"<<endl;
    }else{
        score3=s3;
    }
}



