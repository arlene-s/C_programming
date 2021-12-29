/* 
 * File:   Scores.h
 * Author: Arlene Sagaoinit
 * Created on November 6, 2021, 11:57 PM
 * Purpose: Test Scores class specification
 */

#ifndef SCORES_H
#define SCORES_H

class Scores{
    private:
        int score1;
        int score2;
        int score3;
    public:
        Scores(int s1=0,int s2=0, int s3=0);
        void setSc1(int s1);
        void setSc2(int s2);
        void setSc3(int s3);
        int getSc1()const
            {return score1;}
        int getSc2()const
            {return score2;}
        int getSc3()const
            {return score3;}
        float getAvg()const
            {return (getSc1()+getSc2()+getSc3()*1.0f)/3;}
};


#endif /* SCORES_H */

