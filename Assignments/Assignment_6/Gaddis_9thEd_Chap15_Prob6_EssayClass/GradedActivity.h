/* 
 * File:   GradedActivity.h
 * Author: Arlene Sagaoinit
 * Created on November 28, 2021, 9:49 PM
 * Purpose: GradedActivity bass class specification taken directly from text
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity{
    protected:
        int score;      //To hold score of exam
    public:
        //Default constructor
        GradedActivity()
            {score=0;}
        
        //Constructor
        GradedActivity(int s)
            {score=s;}
        
        //Mutator function
        void setScore(int s)
            {score=s;}
        
        //Accessor functions
        int getScore()const
            {return score;}
        
        //Returns letter grade
        virtual char getLetterGrade();  
};



#endif /* GRADEDACTIVITY_H */

