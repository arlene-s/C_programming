/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on Sept 28th, 2021, 7:22 PM
 * Purpose: Augment a 1-D array by placing a 0
 *          in the front of the array data
 */

#include <iostream>

using namespace std;

int *getData(int &);
int *augment(const int *,int);
void prntAry(const int *,int);

int main(){
	//your code here
	int size;
	int *numbers=getData(size); //Store data into pointer
	prntAry(numbers,size);
	cout<<endl;
	numbers=augment(numbers,size); //Store data of augmented array into pointer
	prntAry(numbers,size+1);
	
	delete []numbers; //Deallocate pointer
	
	return 0;
}

int *getData(int &num){
    cout<<"Enter the size of the array: ";
    cin>>num;
    int *arr=new int[num]; //Dynamic array to store data into
    cout<<"Enter array data: ";
    for(int i=0;i<num;i++)
        cin>>arr[i];
        
    return arr; //Return dynamic array
}

int *augment(const int *a,int num){
    int *arr=new int[num+1]; //Dynamic array with size 1 higher than original array
    arr[0]=0; //Set first element of augmented array to o
    for(int i=0;i<num;i++)
        arr[i+1]=a[i]; //Set the rest of augmented array to contents of original array
        
    return arr;//Return augmented array
}

void prntAry(const int *a,int num){
    for(int i=0;i<num-1;i++)
        cout<<a[i]<<" "; //Print out each element except for the last
    cout<<a[num-1];//Print out last element
}
