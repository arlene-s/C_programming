/* 
 * File:   Prob1Random.h
 * Author: Arlene Sagaoinit
 * Created on December 14, 2021, 1:05 PM
 * Purpose: Prob1Random class specification
 */

#ifndef PROB1RANDOM_H
#define PROB1RANDOM_H

class Prob1Random{
    private:
        char *set;
        char nSet;
        int *freq;
        int numRand;
    public:
        Prob1Random(const char, const char *);
        ~Prob1Random();
        void randFromSet();
        int *getFreq() const;
        char *getSet() const;
        int getNumRand() const;
        void display();
};

#endif /* PROB1RANDOM_H */

