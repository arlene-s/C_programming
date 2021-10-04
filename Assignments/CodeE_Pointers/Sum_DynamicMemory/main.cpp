/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on Sept 27th, 2021, 4:15 PM
 * Purpose: Create an array with the successive sums of a given array
 */

#include <iostream>

using namespace std;

int *getData(int &);  
int *sumAry(const int *,int);
void prntAry(const int *,int);

int main(){
	//your code here
	int size; 
	int *numbers=getData(size); //Pass in data of dynamic array into pointer
	prntAry(numbers,size);
	cout<<endl;
	numbers=sumAry(numbers,size); //Pass in dynamic array with successive sums into pointer
	prntAry(numbers,size);
	
	delete [] numbers; //Delete allocated memory
	return 0;
}

int *getData(int &num){
    cout<<"Enter the size of the array: ";
    cin>>num; //Get the size of the array
    int *arr=new int[num]; //Create dynamic array to store data
    cout<<"Enter array data: ";
    for(int i=0;i<num;i++)
        cin>>*(arr+i); //Store data into dynamic array
        
    return arr; //Return dynamic array to numbers pointer
}

int *sumAry(const int *a,int num){
    int *arr=new int[num]; //Create dynamic array to store successive sums 
    arr[0]=a[0]; //Assign first element of dynamic array to first element of pointer
    for(int i=1;i<num;i++)
        arr[i]=arr[i-1]+a[i]; //Assign next element of dynamic array to the sum of previous element and next element of pointer
        
    return arr; //Return dynamic array with successive sums to pointer
}

void prntAry(const int *a,int num){
    for(int i=0;i<num-1;i++) 
        cout<<*(a+i)<<" "; //Output all contents of const array except last element
    cout<<a[num-1];//Output last element
}
