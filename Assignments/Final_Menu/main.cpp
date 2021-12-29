/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on December 17, 2021, 9:08 PM
 * Purpose: Menu
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//User libraries
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3TableInherited.h"
#include "SSavingsAccount.h"

//Function prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();

int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    bool quit=false;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            default: {quit=true;cout<<"Exiting Menu"<<endl;}
        }
    }while(quit==false);
    
    //Exit stage right!

    return 0;
}

//Description: Displays a prompt for user to print a problem of their choice
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type any number or letter to exit"<<endl<<endl;
}

//                         Problem 1
//Description: Get a sequence of numbers from a set and record the frequencies 
//             of each number pulled, display frequency array
void prblm1(){
    srand(static_cast<unsigned int>(time(0)));
    
    char n=5;
    char rndseq[]={29,34,57,89,126};
    int ntimes=100000;
    Prob1Random a(n, rndseq);
    for(int i=1; i<=ntimes;i++){
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0; i<n; i++){
        cout<<static_cast<int>(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<endl<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}


//                         Problem 2
//Description: Sort a 2dimensional array as a 1 dimensional, use index database sort
//Utilize index array to sort in reference to array, read in from file, display
//sorted array
void prblm2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<char> rc;
    bool ascending=false;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*15];  //10 rows 15 columns from file
    char letter;
    int i=0;
    while(infile>>letter){  //Read in file and store into char array
        if(letter!='\n')ch2[i]=letter;
        i++;
    }
    infile.close();
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++)   //Output file contents
            cout<<ch2[i*15+j];
        cout<<endl;
    }
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    int *zc=rc.sortArray(ch2,10,15,column,ascending);   //Return the index array
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            cout<<ch2[zc[i*15+j]];  //Use index array to output sorted 2d array
        }
        cout<<endl;
    }
    delete []ch2;
}

//                          Problem 3
//Description: Create an augmented array using the sum of each row and column
//             read table from file
void prblm3(){
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++){
        for(int j=0;j<=cols;j++){
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
}

//                         Problem 4
//Description: Calculate savings amount with interest rate and time
//Utilized savings function and recursion function
void prblm4(){
    srand(static_cast<unsigned int>(time(0)));
    
    SavingsAccount mine(-300);
    
    for(int i=1;i<=10;i++){
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    
    mine.toString();
    
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
}