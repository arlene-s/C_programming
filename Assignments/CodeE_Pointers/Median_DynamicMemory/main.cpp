/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on Sept 26th, 2021, 4:24PM
 * Purpose: Find the median of an array and store the median,
 *          size, and integer data into new array
 */

#include <iostream>
#include <iomanip>
using namespace std;

int *getData(int &);
void prntDat(int *,int); 
float *median(int *,int); 
void prntMed(float *);
void mrkSort(int *, int);

int main(){
	//your code here
	int size;
	int *iArr; //Integer pointer
	float *medArr; //float pointer that holds median array contents
	
	iArr=getData(size); //Grab inputs and store into pointer
	prntDat(iArr, size);
	cout<<endl;
	medArr=median(iArr, size);//Analyzes integer array for median and stores contents into pointer
	prntMed(medArr);
	
	//Delete allocated memory
	delete [] iArr;
	delete [] medArr;
	
	return 0;
}

void mrkSort(int *a, int n){
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

int *getData(int &num){
    cout<<"Enter the size of array: ";
    cin>>num;
    int *a=new int[num]; //Dynamic array
    cout<<"Enter the array data: ";
    for(int i=0; i<num; i++){
        cin>>*(a+i); //Store data into dynamic array
    }
        
    return a;//Return dynamic array
}

float *median(int *a,int num){
    float *med=new float[num+2]; //Float dynamic array
    med[0]=num+2;                  //First element in med array is the size
    for(int i=2; i<num+2;i++){   //Copy array
        med[i]=a[i-2];
    }
    mrkSort(a, num);             //Sort array
    if(num%2){
        med[1]=a[num/2];         //If size of array is odd, median is middle number
    }else{
        med[1]=(a[(num-1)/2]+a[num/2])/2.0f;    //Size of array is even, median is 2 middle numbers/2
    }
    return med;//Return float dynamic array
}

void prntDat(int *a, int num){
    for(int i=0;i<num-1;i++)
        cout<<*(a+i)<<" "; //Output all contents of const array except last element
    cout<<a[num-1];//Output last element
}

void prntMed(float *m){
    cout<<m[0]<<" "; //Print first element
    
    cout<<fixed<<setprecision(2); //Set output to 2 after decimal
    for(int i=1;i<m[0];i++){
        cout<<m[i];
        if(i<m[0]-1)cout<<" ";
    }
}