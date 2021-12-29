/* 
 * File:   Prob3Table.h
 * Author: Arlene Sagaoinit
 * Created on December 16, 2021, 11:21 PM
 * Purpose: Prob3Table Class specification
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

#include <fstream>
using namespace std;

template<class T>
class Prob3Table{
    protected:
        int rows; //Number of rows in the table
        int cols; //Number of cols in the table
        T *rowSum; //RowSum array
        T *colSum; //ColSum array
        T *table; //Table array
        T grandTotal; //Grand total
        void calcTable(){
            T rSum,cSum;
            for(int i=0; i<rows;i++){       //Sum rows
                rSum=0;
                for(int j=0; j<cols; j++){
                    rSum+=table[i*cols+j];  //Grab sum of each row
                }
                rowSum[i]=rSum;             //Set sums to rowSum array
                grandTotal+=rowSum[i];      //Calculate grandtotal of the new row
            }
            for(int i=0; i<cols;i++){       //Sum columns of array
                cSum=0;
                for(int j=0; j<rows; j++)
                    cSum+=table[j*cols+i];  //Grab sum of each column
                colSum[i]=cSum;             //Set sums to new colSum array
            }  
        }
    public:
        Prob3Table(char *filename,int r,int c){
            grandTotal=0;
            rows=r;
            cols=c;
            table=new T[rows*cols];
            rowSum=new T[rows];
            colSum=new T[cols];
            T num;
            int i=0;
            fstream infile;
            infile.open(filename,ios::in);
            while(infile>>num){ //Read in file
                table[i]=num;
                i++;
            }
        }
        ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
        const T *getTable(){return table;}
        const T *getRowSum(){return rowSum;};
        const T *getColSum(){return colSum;};
        T getGrandTotal(){return grandTotal;};
};



#endif /* PROB3TABLE_H */

