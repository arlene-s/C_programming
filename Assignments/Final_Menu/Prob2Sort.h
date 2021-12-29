/* 
 * File:   Prob2Sort.h
 * Author: Arlene Sagaoinit
 * Created on December 14, 2021, 2:48 PM
 * Purpose: Prob2Sort class specification
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H

#include <cstdlib>
using namespace std;

template<class T>
class Prob2Sort{
    private:
        int *index;
    public:
        Prob2Sort(){index=NULL;};
        ~Prob2Sort(){delete []index;};
        int *sortArray(const T* array, int row, int colmax, int col, bool a){
            index=new int[row*colmax];
            for(int i=0; i<row*colmax;i++)
                index[i]=i; //Assign index value to array
            if(a==false){   //Descending
                for(int i=0; i<row-1; i++){
                    for(int j=i+1; j<row;j++){  //reference array to index
                        if(array[index[i*colmax+col]]<array[index[j*colmax+col]]){
                            for(int k=0; k<colmax;k++){
                                int temp=index[j*colmax+k]; //Swap indexes not array values
                                index[j*colmax+k]=index[i*colmax+k];
                                index[i*colmax+k]=temp;
                            }
                        }
                    }
                }
            }else{          //Ascending
                for(int i=0; i<row-1; i++){
                   for(int j=i+1; j<row;j++){
                       if(array[index[i*colmax+col]]>array[index[j*colmax+col]]){
                           for(int k=0; k<colmax;k++){
                               int temp=index[i*colmax+k];
                               index[i*colmax+k]=index[j*colmax+k];
                               index[j*colmax+k]=temp;
                           }
                       }
                   }
                }
            }
            return index;
        }
    
};






#endif /* PROB2SORT_H */

