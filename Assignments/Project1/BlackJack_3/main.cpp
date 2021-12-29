/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on October 30 2021 7:20pm
 * Purpose: Third version of black jack game
 *          -Added hit function to allow user to pull a card while hand total < 21
 *          -Added chckAce function to change value of ace card when player goes over
 *          -Created structure of player's card information. Contains:
 *             ~Dynamic array holding player's hand
 *             ~Index/size of hand array
 *             ~Total variable holding hand total
 *             ~AceElem variable holding element of ace card in hand array
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <ctime>      //srand()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
struct Player{
    int *cards;       //Players hand dynamic array
    int index;        //Current filled size of array
    int total;        //Total of hand array
    int aceElem;      //Element of ace in hand array if ace pulled
};
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
char card(Player *, char []);   //Returns char from card deck
void chckAce(Player *);         //Check for ace card chosen
void hit(Player *, char []);    //Allows player to hit while total < 21
void calcTot(Player *);         //Calculates players hand total
void stats(Player *, Player *); //Compare players totals and display win or loss

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables here
    //Initialize variables here
    int size=10;                    //Size of hand too big
    Player *user=new Player;        //Define a Player user and give it memory
    user->cards=new int[size];      //Allocate memory to array holding player's hand
    Player *dealer=new Player;      //Define a Player dealer and give it memory
    dealer->cards=new int[size];    //Allocate memory to array holding dealer's hand
    user->index=0;                  //Initialize index for cards array and hand total
    dealer->index=0;
    user->total=0;
    dealer->total=0;
    user->aceElem=-1;               //Initialize ace element to -1, changes when ace card pulled
    dealer->aceElem=-1;
    //Char array holding deck('T' for 10 card)
    char deck[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Your first card: "<<card(user,deck)<<endl;   //Pull card from deck using random number
    cout<<"Your second card: "<<card(user,deck)<<endl;  //Output cards
    calcTot(user);  //Calculate total of cards pulled
    cout<<"Your total: "<<user->total<<endl;
    cout<<endl;
    chckAce(user);  //Check if card pulled was an ace
    cout<<"Dealers first card: "<<card(dealer,deck)<<endl;//Ouput dealers first card
    
    //If users hand total < 21, call function to prompt user to hit
    //prompt user while total<21 and until they want to stop
    if(user->total<21){
        hit(user,deck);
        cout<<"Your total: "<<user->total<<endl;
    }
    cout<<"Dealers second card: "<<card(dealer,deck)<<endl; //Grab second card for dealer
    calcTot(dealer);            //Calculate the dealers hand total
    while(dealer->total<17){    //Dealer pulls cards until the total is 17 or greater
        cout<<"Dealer hits: "<<card(dealer,deck)<<endl;
        calcTot(dealer);        //Calculate new hand total
        chckAce(dealer);        //Check if card pulled is an ace, if went over, change value to 1
    }
    cout<<"Dealer total: "<<dealer->total<<endl;
    cout<<endl;
    
    //Display the results
    stats(user, dealer);        //Compare user and dealer totals and display win or loss
    
    //Deallocate
    delete []user->cards;       //Destroy cards array in struct
    delete user;                //Destroy struct
    delete []dealer->cards;     //Do the same for dealer 
    delete dealer;
    return 0;
}

void stats(Player *playr, Player *dealr){
    if(playr->total>21){
        cout<<"You lose!"<<endl;
    }else if(playr->total<21){
        if(dealr->total<21){
            cout<<(playr->total>dealr->total?"You win!":"You lose!")<<endl;
        }else if(dealr->total>21){
            cout<<"You win!"<<endl;
        }else{
            cout<<"You lose!"<<endl;
        }
    }else{
        if(playr->total!=dealr->total){
            cout<<"You win!"<<endl;
        }else{
            cout<<"tie you lose"<<endl;
        }
    }
}
char card(Player *playr, char deck[]){
    int elem=rand()%13; //Element number from 0 to 12
    if(deck[elem]>='2'&&deck[elem]<='9'){
        playr->cards[playr->index]=deck[elem]-48;
    }
    else{//Face card pulled
        //if ace is pulled, set aceElem to current index of playr cards array
        playr->aceElem=deck[elem]=='A'?playr->index:playr->aceElem;
        //If ace is pulled, default its value to 11, if not ace set value to 10
        playr->cards[playr->index]=deck[elem]=='A'?11:10;
    }
    playr->index++;//Increment index for next card pull
    return deck[elem];
}

void chckAce(Player *playr){
    if(playr->total>21&&playr->aceElem!=-1){
        playr->cards[playr->aceElem]=1; //If player has an ace and goes over, set value to 1
        calcTot(playr);//Recalculate total with ace as 1
    }
}

void calcTot(Player *playr){
    int sum=0;  //Variable to hold sum of players hand
    for(int i=0; i<playr->index;i++)    //Loop through hand
        sum+=playr->cards[i];           //Add each value in hand to sum
    playr->total=sum;                   //Return sum
}

void hit(Player *playr, char deck[]){
    bool quit=false;    //Set to true when user wants to stop hitting
    //Prompt user to hit while quit is false and hand total < 21
    while(quit==false&&playr->total<21){
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
            cout<<"card: "<<card(playr,deck)<<endl; //Pull card
            calcTot(playr);     //Calculate total
            chckAce(playr);     //Check if card pulled is an ace
        }else{
            quit=true;          //If no, set quit to true and exit loop
        }
    }
}