/* 
 * File:   Prob3Inherited.h
 * Author: Arlene Sagaoinit
 * Created on December 16, 2021, 11:24 PM
 * Purpose: Prob3Table class specification
 */

#ifndef PROB3INHERITED_H
#define PROB3INHERITED_H

#include "Prob3Table.h"

template<class T>
class Prob3TableInherited:public Prob3Table<T>{
    protected:
        T *augTable; //Augmented Table with sums

    public:
        Prob3TableInherited(char *file,int row,int col):Prob3Table<T>(file,row,col){
            this->calcTable();
            augTable=new T[(row+1)*(col+1)];
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){   //Copy original array to augmented array
                    augTable[i*(col+1)+j]=this->table[i*col+j];
                }
            }
            for(int i=0; i<row;i++)
               augTable[i*(col+1)+col]=this->rowSum[i]; //copy rowSum to new augmented column
            for(int i=0; i<col;i++)                     //copy colSum to new augmented row
                augTable[row*(col+1)+i]=this->colSum[i];
            augTable[(row+1)*(col+1)-1]=this->getGrandTotal(); //Assign last element to grandTotal
        }
        ~Prob3TableInherited(){delete [] augTable;}; //Destructor
        const T *getAugTable(){return augTable;};
};



#endif /* PROB3INHERITED_H */

