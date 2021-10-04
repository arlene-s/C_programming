/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on Sept 28th, 2021, 10:00 PM
 */

#include <iostream>

int **getData(int &,int &);
void printDat(const int * const *,int,int);
int **augment(const int * const *,int,int);
void destroy(int **,int);

using namespace std;

int main(){
	//your code here
	int rows, cols;
	int **numbers=getData(rows,cols); //Store data into 2d pointer
	printDat(numbers,rows,cols);
	numbers=augment(numbers,rows+1,cols+1); //Store 2d augmented array into 2d pointer
	printDat(numbers,rows+1,cols+1);
	
	destroy(numbers,rows); //Destroy allocated memory
	return 0;
}

int **getData(int &rows,int &cols){
    cout<<"Enter number of rows and columns: ";
    cin>>rows>>cols;
    int **arr=new int*[rows]; //Integer 2d pointer to hold data
    cout<<"Enter the array data: ";
    for(int i=0;i<rows;i++){
        arr[i]=new int[cols]; //Assign each row an array with size column
        for(int j=0;j<cols;j++)
            cin>>arr[i][j];
    }
    return arr; //Return 2d array
}

int **augment(const int * const *a,int rows,int cols){
    int **arr=new int*[rows]; //Integer 2d pointer to hold augmented array
    for(int i=0;i<rows;i++)
        arr[i]=new int[cols]; //Assign each row an array with size column
    for(int i=0; i<cols;i++)    //Assign first row to all 0
        arr[0][i]=0;
    for(int i=0; i<rows;i++)     //Assign first column to all 0
        arr[i][0]=0;
    for(int i=1;i<rows;i++){
        for(int j=1;j<cols;j++)
            arr[i][j]=a[i-1][j-1]; //Assign rest of 2d array with contents of original 2d array
    }
    
    return arr; //Return augmented 2d array
}

void printDat(const int * const *a,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols-1;j++)
            cout<<a[i][j]<<" "; //Print each element except for last column
        cout<<a[i][cols-1];     //Print last column
        cout<<endl;
    }
    
    
}

void destroy(int **a,int rows){
    for(int i=0;i<rows;i++)
        delete [] a[i]; //Delete contents of each row in 2d array
    delete [] a; //Delete 2d array
}

