/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on September 6, 2021, 8:17 PM
 * Purpose:  Searches through an array of strings for user's input and returns location of input
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void selSort(string[],int);         //Selection sort to put names in alphabetical order
int bnarySrch(string[],int,string); //Searches for user input and returns location int

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    string name;            //For user input
    const int size=20;      //Size of array
    string names[size]={"Collins, Bill","Smith, Bart","Allen, Jim","Griffin, Jim",
                        "Stamey, Marty","Rose, Geri","Taylor, Terri","Jonhson, Jill",
                        "Allison, Jeff","Looney, Joe","Wolfe, Bill","James, Jean",
                        "Weaver, Jim","Pore, Bob","Rutherford, Greg","Javens, Renee",
                        "Harrison, Rose","Setzer, Cathy","Pike, Gordon","Holland, Beth"};
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    selSort(names, size);   //Sorts contents of array to be displayed in alphabetical order
    
    for(int i=0;i<size;i++) //Display names in array after sorted
        cout<<names[i]<<endl; 
    
    cout<<endl<<"Enter string name (Last name, First name): "; //Prompt user to find name
    getline(cin, name);
    
    int location=bnarySrch(names, size, name); //Searches array for input and returns location
    
    //Display the results
    if(location==-1)
        cout<<"That name was not found!"<<endl;
    else
        cout<<"The name is located at: "<<location<<endl;
    
    return 0;
}
void selSort(string a[],int size){
    for(int i=0;i<size-1;i++){
        int min=i;//Set first element in array as first name in order
        //Compare next element to first element, if less than first element, 
        //update as next name in order
        for(int j=i;j<size;j++){
            if (a[j]<a[min])
                min = j;
        }
        swap(a[i], a[min]); //Swap previous element with new name
    }
}

int bnarySrch(string a[],int size, string name)
{
    int low=0;//First element in array
    int high=size-1;//Last element in array
    int middle=(low+high)/2;//Starting location for guess
    string guess=a[middle];
    
    while(guess!=name && low<=high){//Keep guessing until guess is correct
        if(guess<name){
            low=middle+1;//Set new low, search to the right of it
            middle=(low+high)/2;//Update new middle
            guess=a[middle];//Update new guess
        }
        else{//Guessed to the right of name
            high=middle-1;//Set new high, search to the left of it
            middle=(low+high)/2;//Update new middle
            guess=a[middle];//Update new guess
        }
    }
    
    if(low>high)//Went out of range, name not found
        return -1;
    else
        return middle;//Location of name
}

