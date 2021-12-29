/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on October 25, 2021, 3:40 AM
 * Purpose: First version of black jack game
 *          -uses static arrays for card deck, user, and dealer
 *          -uses srand() to create random number to pull from card deck array
 *          -returns card to player
 *          -calculates card total and compares players totals to each other
 *          -display win or loss
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <ctime>      //srand()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

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
    int playTot=0, dealTot=0;   //players hand totals
    char hit;
    
    //Initialize variables here
    cout<<"This is the game of black jack"<<endl;
    cout<<"Dealer will deal you two cards one face up and the second face down"<<endl;
    
    //Create players first card
    int index=rand()%13;    //Grab an element number from cards array
    cout<<"Your first card: "<<cards[index]<<endl;//Return value from cards array
    if(cards[index]>='2'&&cards[index]<='9'){
        //Convert char value to integer and store into players hand array
        playCrd[0]=cards[index]-48;
    }
    else{//Value is face card
        //If face card is an Ace default to 11
        //Otherwise if face card is not an ace set to 10 
        playCrd[0]=cards[index]=='A'?11:10;
    }
    
    //Create dealers first card
    index=rand()%13;
    cout<<"Dealers first card: "<<cards[index]<<endl;
    if(cards[index]>='1'&&cards[index]<='9'){
        dealCrd[0]=cards[index]-48;
    }
    else{
        dealCrd[0]=cards[index]=='A'?11:10;
    }
    
    //Create players second card
    index=rand()%13;
    cout<<"Your second card: "<<cards[index]<<endl;
    if(cards[index]>='1'&&cards[index]<='9'){
        playCrd[1]=cards[index]-48;
    }
    else{
        playCrd[1]=cards[index]=='A'?11:10;
    }
          
    //Create dealers second card
    index=rand()%13;
    cout<<"Dealers second card: "<<cards[index]<<endl;
    if(cards[index]>='1'&&cards[index]<='9'){
        dealCrd[1]=cards[index]-48;
    }
    else{
        dealCrd[1]=cards[index]=='A'?11:10;
    }
    
    //Map inputs to outputs here, i.e. the process
    playTot=playCrd[0]+playCrd[1];  //Calculate players hand total
    dealTot=dealCrd[0]+dealCrd[1];
    
    //Display results
    cout<<"Your total: "<<playTot<<endl;
    cout<<"Dealer total: "<<dealTot<<endl;
    cout<<endl;
    
    if(playTot<21){
        if(dealTot<21){
            if(playTot>dealTot){
                cout<<"You win!"<<endl;
            }else if(playTot<dealTot){
                cout<<"You lose!"<<endl;
            }else{
                cout<<"You lose!"<<endl;
            }
        }else if(dealTot>21){
            cout<<"You win!"<<endl;
        }else{
            cout<<"You lose!"<<endl;
        }
    }else if(playTot==21){
        cout<<"You win!"<<endl;
    }else{
        cout<<"Bust! You lose!"<<endl;
    }
    
    return 0;
}
