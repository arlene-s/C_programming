/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on Sept 26th, 2019, 6:12 PM
 * Purpose: Sort a dynamic array and reverse its contents
 */

#include <iostream>

using namespace std;

int *getData(int &);
int *sort(const int *, int);
int *reverse(const int *, int);
void prntDat(const int *, int);

int main(){
	//your code here
	int size; //Declare size of array
	int *numbers=getData(size); //Store data of dynamic array into numbers pointer
	numbers=sort(numbers,size); //Store data of sorted dynamic array into numbers pointer
	prntDat(numbers,size);
	cout<<endl;
	numbers=reverse(numbers,size);//Store data of reversed dynamic array into numbers pointer
	prntDat(numbers,size);
	
	//Delete allocated memory
	delete [] numbers;
	
	return 0;
}
int *getData(int &num){
    cout<<"Enter the size of array: ";
    cin>>num;
    int *a=new int[num];//create dynamic array to store data
    cout<<"Enter the data of array: ";
    for(int i=0;i<num;i++)
        cin>>*(a + i);//Get data and store into dynamic array
        
    return a;//return dynamic array to numbers pointer
}

int *sort(const int *a, int num){
    int *arr;
    arr=new int[num];//Create dynamic array to sort data
    for(int i=0;i<num;i++)
        *(arr+i)=*(a+i);//copy data of constant pointer into dynamic array to sort
    //Find the smallest element in List i
    for(int i=0;i<num-1;i++){
        //Swap as you go to place the smallest element at the top
        for(int j=i+1;j<num;j++){
            //Logic swap
            if(*(arr+i)>*(arr+j)){
                *(arr+i)=*(arr+i)^*(arr+j);
                *(arr+j)=*(arr+i)^*(arr+j);
                *(arr+i)=*(arr+i)^*(arr+j);
            }
        }
    }
    
    return arr;//Return sorted dyanmic array to numbers pointer
}

int *reverse(const int *a, int num){
    int *arr;
    arr=new int[num];//Create dynamic array to store reversed data
    //Same as sort array except sorting in reverse order
    for(int i=0;i<num;i++)
        *(arr+i)=*(a+i);
    //Find the largest element
    for(int i=0;i<num-1;i++){
        //Swap until the largest element at the top
        for(int j=i+1;j<num;j++){
            //Logic swap
            if(*(arr+i)<*(arr+j)){
                *(arr+i)=*(arr+i)^*(arr+j);
                *(arr+j)=*(arr+i)^*(arr+j);
                *(arr+i)=*(arr+i)^*(arr+j);
            }
        }
    }
    return arr; //Return reversed array to numbers pointer
}

void prntDat(const int *arr, int num){
    for(int i=0;i<num-1;i++)
        cout<<*(arr + i)<<" "; //Output all contents of const array except last element
    cout<<arr[num-1];//Output last element
}