/* 
 * File:   Hand.h
 * Author: Arlene Sagaoinit
 * Created on November 14, 2021, 6:40 PM
 * Purpose: Hand Class Specification
 */

#ifndef HAND_H
#define HAND_H

#include "Deck.h"
#include <iostream>
using namespace std;

//Hand class inherited from Deck class
class Hand{
    private:
        int hndSize;    //Size of hand
        int *cards;     //Array holding values of player's hand
        int indx;       //Index of cards array
        int handTot;    //Total of player's hand
        int aceElem;    //Index of Ace card in hand
    public:
        Hand(int n){
            hndSize=n<2?2:n;
            cards=new int[hndSize];
            indx=0;
            handTot=0;
            aceElem=-1;
        }
        
        ~Hand(){
            delete []cards;
        }
        
        string dealCrd(Deck &deck,int &n){
            int elem=n;
            cards[indx]=deck.val(elem);
            if(deck.face(indx)=="A")
                aceElem=indx;
            indx++;
            n++;
            return deck.face(elem)+deck.suit(elem);
        }
        void calcTot(){
            int sum=0;      //Variable to hold sum of players hand
            for(int i=0; i<indx;i++)   //Loop through hand
                sum+=cards[i];          //Add each value in hand to sum
            handTot=sum;                //Return sum
        }
        int total(){
            calcTot();
            return handTot;
        }
        
        void hit(Deck &deck, int n){
            int elem=n;
            bool quit=false;    //Set to true when user wants to stop hitting
            //Prompt user to hit while quit is false and hand total < 21
            while(quit==false&&total()<21){
                cout<<"Hit? (y/n): ";
                char hit;
                cin>>hit;
                //If input is uppercase, convert to lowercase 
                //Only two options: 'y' or 'n' if not chosen, prompt until one of the two chosen
                while(tolower(hit)!='y'&&tolower(hit)!='n'){
                    cout<<"Invalid please enter 'y' or 'n'"<<endl;
                    cin>>hit;
                }
                if(tolower(hit)=='y'){  //If yes
                    cout<<"card: "<<dealCrd(deck,elem);
                    cout<<endl;
                    calcTot();
                    chckAce();
                }else{
                    quit=true;          //If no, set quit to true and exit loop
                }
            }
        }
        
        void chckAce(){
            //If player has an ace and goes over, set value to 1
            if(total()>21&&aceElem!=-1){
                cards[aceElem]=1;
                calcTot();//Recalculate total with ace as 1
            }
        }
    
};

#endif /* HAND_H */