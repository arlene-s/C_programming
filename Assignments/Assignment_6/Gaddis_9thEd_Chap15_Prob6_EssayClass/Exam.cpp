/* 
 * File:   Exam.h
 * Author: Arlene Sagaoinit
 * Created on November 28, 2021, 9:58 PM
 * Purpose: Exam class derived from GradedActivity class specification
 */

#include <iostream>
#include "GradedActivity.h"
#include "Exam.h"

Exam::Exam(int gram, int spel, int len, int cont):GradedActivity(){
    setGram(gram);
    setSpel(spel);
    setLen(len);
    setCont(cont);
}

//Redefined getLetterGrade() from base class
char Exam::getLetterGrade(){
    score=spelling+grammer+corrLen+content;
    setScore(score);
    return GradedActivity::getLetterGrade();
}


