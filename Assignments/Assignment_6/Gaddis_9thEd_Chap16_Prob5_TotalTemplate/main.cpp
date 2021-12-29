/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 30, 2021, 10:32 PM
 * Purpose: Create a template class that will return the total of values entered by user
 */

#include <iostream>
using namespace std;

//Function prototypes
template <class T>
class Total{
    private:
        T *values;      //Dynamic array holding values entered by user
        int size;       //Size of array
        T total;        //Total of values in array
        //Utility function calculates total
        void calcTot(){ 
            for(int i=0; i<size;i++){
                total+=values[i];
            }
        }
    public:
        //Default constructor
        Total()
            {size=0; total=0;}
        //Constructor
        Total(int n){
            setSize(n);
            total=0;
            values=new T[size];       //Allocate memory
            for(int i=0; i<size;i++){
                values[i]=0;          //Initialize values in array to 0
            }
        }
        //Destructor
        ~Total()
            {delete []values;}
        
        void setSize(int n)
            {size=n;}                 //Set the size of array
        
        void setVal(T val, int pos)   //Set a value in array
            {values[pos]=val;}
        
        int getSize()
            {return size;}
        
        T getTotal(){
            calcTot();
            return total;
        }
};

int main(int argc, char** argv) {
    //Declare variables
    int arySize,num;
    
    //Map inputs to outputs
    cout<<"Enter size of numbers array: ";
    cin>>arySize;
    
    Total<int> total(arySize);  //Define class 
    
    //User enters values in array
    for(int i=0; i<total.getSize();i++){
        cout<<"Enter number "<<i+1<<": ";
        cin>>num;
        total.setVal(num,i);
    }
    
    //Display results
    cout<<endl;
    cout<<"Total: "<<total.getTotal()<<endl;

    return 0;
}

