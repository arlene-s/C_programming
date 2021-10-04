/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on Sept 27, 2021, 12:57 PM
 * Purpose: Return the sum of all the elements in a 2D array
 */

#include <iostream>

using namespace std;

int **getData(int &,int &); 
void prntDat(const int* const *,int,int);
void destroy(int **,int,int);   
int sum(const int * const *, int,int);  

int main(){
	//your code here
	int rows, cols;
	int **numbers=getData(rows, cols); //Store data into pointer
	prntDat(numbers, rows, cols);
	
	cout<<sum(numbers, rows, cols); //Print the sum of 2d array
	destroy(numbers, rows, cols); //Deallocate memory
	
	return 0;
}

int **getData(int &rows,int &cols){
    cout<<"Enter the number of rows and columns: ";
    cin>>rows>>cols;
    int **arr=new int *[rows];//2d dynamic array
    cout<<"Enter the array data: ";
    for(int i=0;i<rows;i++){
        arr[i]=new int[cols]; //Assign each row of dynamic array to an array with size columns
        for(int j=0;j<cols;j++)
            cin>>arr[i][j]; //Store data into 2d array
    }
    
    return arr; //Return 2d dynamic array
}

int sum(const int * const *a, int rows,int cols){
    int sum=0; //Integer variable to hold total sum of values in 2d array
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            sum+=a[i][j]; //Add each element into sum
    }
    
    return sum; //Return total sum
}

void prntDat(const int* const *a,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols-1;j++)
            cout<<a[i][j]<<" "; //Print every row and column except the last column
        cout<<a[i][cols-1]; //Print last column
        cout<<endl;
    }
}

void destroy(int **a,int rows,int cols){
    for(int i=0;i<rows;i++)
        delete [] a[i]; //Delete contents of every row of array
    delete []a; //Delete array
}