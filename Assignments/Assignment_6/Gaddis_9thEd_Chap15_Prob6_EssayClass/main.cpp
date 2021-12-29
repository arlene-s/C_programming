/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 28, 2021, 9:45 PM
 * Purpose: Design an Essay class derived from GradedActivity class from chapter.
 *          Calculate user's essay score based off points from grading sections
 *              Grammer: 30 points
 *              Spelling: 20 points
 *              Correct Length: 20 points
 *              Content: 30 points
 */

#include <iostream>
using namespace std;
//User libraries
#include "Exam.h"

//Function prototypes
void display(GradedActivity &);

int main(int argc, char** argv) {
    //Define variables
    GradedActivity test1(65);
    Exam test2;
    
    //Initialize variables
    //Set scores for each grading section
    test2.setGram(20);
    test2.setSpel(20);
    test2.setLen(15);
    test2.setCont(25);
    
    //Display results
    cout<<"First test: "<<endl;
    display(test1);
    cout<<"Second test: "<<endl;
    display(test2);
   
    return 0;
}

void display(GradedActivity &activity){
    cout<<"Test score: "<<activity.getLetterGrade()<<endl;
}
