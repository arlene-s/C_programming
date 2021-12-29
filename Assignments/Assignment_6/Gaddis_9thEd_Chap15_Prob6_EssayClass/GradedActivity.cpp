/* 
 * File:   GradedActivity.h
 * Author: Arlene Sagaoinit
 * Created on November 28, 2021, 9:49 PM
 * Purpose: GradedActivity bass class member functions taken directly from text
 */

#include "GradedActivity.h"

char GradedActivity::getLetterGrade(){
    char letter; //To hold the letter grade
    
    if(score>89)
        letter='A';
    else if(score>79)
        letter='B';
    else if(score>69)
        letter='C';
    else if(score>59)
        letter='D';
    else
        letter='F';
    
    return letter;
}
