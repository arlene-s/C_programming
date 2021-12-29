/* 
 * File:   Exam.h
 * Author: Arlene Sagaoinit
 * Created on November 28, 2021, 9:58 PM
 * Purpose: Exam class derived from GradedActivity class specification
 */

#ifndef EXAM_H
#define EXAM_H

#include "GradedActivity.h"

class Exam:public GradedActivity{
    private:
        int grammer;    //Exam graded off grammer
        int spelling;   //Spelling
        int corrLen;    //Correct length
        int content;    //Exam content
    public:
        //Default Constructor calls base class default constructor
        Exam():GradedActivity()
            {grammer=0;
             spelling=0;
             corrLen=0;
             content=0;}
        
        //Constructor
        Exam(int,int,int,int);
        
        //Mutator functions to set the scores for each grading section
        void setGram(int gram)
            {grammer=gram;}
        void setSpel(int spel)
            {spelling=spel;}
        void setLen(int len)
            {corrLen=len;}
        void setCont(int cont)
            {content=cont;}
        
        //Accessor functions to grab the scores for each grading section
        int getGram()
            {return grammer;}
        int getSpel()
            {return spelling;}
        int getLen()
            {return corrLen;}
        int getCont()
            {return content;}
        
        //Redefined function from base class
        virtual char getLetterGrade();
};


#endif /* EXAM_H */

