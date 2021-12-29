/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on October 25, 2021, 3:40 AM
 * Purpose: Second version of black jack game
 *          -implement functions
 *          -calls a function to return a char as players card
 *          -calls a function to calculate hand totals
 *          -calls a function to compare totals and display users win or loss
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <ctime>      //srand()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
char card(int [], char [], int &);  //Returns a char from card deck
int calcTot(int [],int );           //Calculates the total of each players hand
void stats(const int, const int);   //Compare totals and display win or loss
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    //Create static char array to represent deck ('T' for 10 card)
    char cards[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    int size=10;            //Largest size to fit size of hand
    int playCrd[size];      //Array holding players cards
    int dealCrd[size];      //Array holding dealers cards
    int playTot=0, dealTot=0,plyrIdx=0,dealIdx=0,input;
    char hit;
    
    //Initialize variables here
    cout<<"This is the game of black jack"<<endl;
    cout<<"Dealer will deal you two cards one face up and the second face down"<<endl;
    
    //Create players first card
    cout<<"Your first card: "<<card(playCrd,cards,plyrIdx)<<endl;//Return value from cards array
    //Create dealers first card
    cout<<"Dealers first card: "<<card(dealCrd,cards,dealIdx)<<endl;
    //Create players second card
    cout<<"Your second card: "<<card(playCrd,cards,plyrIdx)<<endl;
    //Create dealers second card
    cout<<"Dealers second card: "<<card(dealCrd,cards,dealIdx)<<endl;
    
    //Map inputs to outputs here, i.e. the process 
    playTot=calcTot(playCrd,plyrIdx);   //Calculate card totals
    dealTot=calcTot(dealCrd,dealIdx);
    
    //Display results
    cout<<"Your total: "<<playTot<<endl;
    cout<<"Dealer total: "<<dealTot<<endl;
    cout<<endl;
    stats(playTot, dealTot);    //Compare totals, display win or loss
    
    return 0;
}

void stats(const int pTotal, const int dTotal){
    if(pTotal<21){
        if(dTotal<21){
            if(pTotal>dTotal){
                cout<<"You win!"<<endl;
            }else if(pTotal<dTotal){
                cout<<"You lose!"<<endl;
            }else{
                cout<<"You lose!"<<endl;
            }
        }else if(dTotal>21){
            cout<<"You win!"<<endl;
        }else{
            cout<<"You lose!"<<endl;
        }
    }else if(pTotal==21){
        cout<<"You win!"<<endl;
    }else{
        cout<<"Bust! You lose!"<<endl;
    }
}

char card(int array[], char deck[], int &idx){
    int elem=rand()%13; //Element number from 0 to 12
    if(deck[elem]>='2'&&deck[elem]<='9'){
        //Convert char value to integer and store into players hand array
        array[idx]=deck[elem]-48;
    }
    else{//Value is face card
        //If face card is an Ace default cardVal to 11
        //Otherwise if face card is not an ace set cardVal to 10 
        array[idx]=deck[elem]=='A'?11:10;
    }
    idx++;
    return deck[elem];
}

int calcTot(int array[],int idx){
    int sum=0;
    for(int i=0; i<idx;i++){
        sum+=array[i];
    }
    return sum;
}