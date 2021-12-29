/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 1, 2021, 6:10 PM
 * Purpose:  Fourth version of black jack game
 *           -Added Hand struct to separate player's card info and player's stats
 *           -Nested Hand struct inside Player struct
 *              ~Player struct contains:
 *                  -Hand info:
 *                      hand array;
 *                      index;
 *                      hand total;
 *                      ace card index;
 *                  -bet amount;
 *                  -total chips;
 *                  -num games played;
 *                  -num wins;
 *                  -num losses; 
 *           -Added do while loop to play as much games user wants to play
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <ctime>
#include <iomanip>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
struct Hand{        //Structure containing players hand details
    int *cards;     //Array holding players hand
    int index;      //Current index/size of array
    int handTot;    //Current sum of players hand
    int aceElem;    //Ace card index, val to change when total>21
};

struct Player{           //Structure containing players card details, bet amount, total chips
    Hand *plyrHnd;       //Pointer to hand structure for holding players hand info
    int betAmt;          //Players bet amount
    int chipTot;         //Players money total
    unsigned int games;  //Number of games 
    unsigned int wins;   //Players number of wins
    unsigned int losses; //Number of losses
};

Player *playr();                 //Returns a Player struct with initialized values
Hand *hand();                    //Returns a Hand struct with initialized values
char card(Player *, char []);    //Assigns card to player
void calcTot(Player *);          //Calculate total of hand
void hit(Player *, char []);     //Ask user if want another card
void stats(Player *, Player *);  //Display win or loss
void chckAce(Player *);          //Check if players hand contains an ace

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    char input;                  //User input to play game again (y/n)
    Player *user=playr();        //Create a player struct for user
    Player *dealer=playr();      //Create a player struct for dealer
    
    //Initialize variables here
    //Static array holding card values ('T' for 10 card)
    char deck[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Play Blackjack!"<<endl;
    cout<<"Beat the dealer by gaining a hand total close to 21 without going over. "<<endl
        <<"If you have an ace card, its value is 11 until you go over 21. When "
        <<"you go over, your ace will change to 1 and you can continue hitting "
        <<"until you go over again."<<endl
        <<"Min bet: $20"<<endl<<"Max bet: $500"<<endl;
    
    do{
        cout<<"--------------------------------------"<<endl;
        user->plyrHnd=hand();       //Allocate memory to hand info struct
        dealer->plyrHnd=hand();
        cout<<"Place your bet: ";
        cin>>user->betAmt;          //Collect users bet amount
        
        //Pull cards and display them
        cout<<"Your cards: "<<card(user, deck)<<" "<<card(user, deck)<<endl;
        calcTot(user);              //Calculate total of hand
        chckAce(user);              //Check if ace card pulled, if went over change val to 1
        //Display users total
        cout<<"Total: "<<user->plyrHnd->handTot<<endl<<endl;

        cout<<"Dealers first card: "<<card(dealer,deck)<<endl;
        //If users hand total < 21, call function to prompt user to hit
        //prompt user while total<21 and until they want to stop
        if(user->plyrHnd->handTot<21){
            hit(user, deck);
            cout<<"Total: "<<user->plyrHnd->handTot<<endl<<endl;
        }

        cout<<"Dealers second card: "<<card(dealer,deck)<<endl;//Grab second card for dealer
        calcTot(dealer);//Calculate the dealers hand total
        while(dealer->plyrHnd->handTot<17){//Dealer pulls cards until the total is 17 or greater
            cout<<"Dealer hits: "<<card(dealer,deck)<<endl;
            calcTot(dealer);               //Calculate new total
            chckAce(dealer);               //Check if card pulled is an ace
        }
        //Display dealers total
        cout<<"Dealers total: "<<dealer->plyrHnd->handTot<<endl<<endl;

        //Display the results
        stats(user, dealer);      //Compare user and dealer totals and display win or loss
        
        //Deallocate memory
        //Delete only the player's hand info inside do while loop to reset their hand
        //but keep players stats -> betAmt, chipTot, num games, wins, losses
        delete []user->plyrHnd->cards;  //Destroy users hand, hand total, and size
        delete user->plyrHnd;           //Destroy Hand structure
        delete []dealer->plyrHnd->cards;
        delete dealer->plyrHnd;
        
        cout<<"Would you like to play again? (y/n) ";
        cin>>input;
        //If input uppercase, convert to lowercase
        //User can only enter 'y' or 'n', loop while input invalid
        while(tolower(input)!='y'&&tolower(input)!='n'){
            cout<<"Invalid please enter 'y' or 'n"<<endl;
            cin>>input;
        }
    }while(tolower(input)=='y');    //Start game again if input == 'y'
    
    //End of game, display other stats
    cout<<"***************************************"<<endl;
    cout<<"Total Games Played: "<<user->games<<endl;
    cout<<"Total Wins: "<<user->wins<<endl;
    cout<<"Total Losses: "<<user->losses<<endl;
    cout<<"***************************************"<<endl;
    
    //Deallocate memory
    //Now when user is done playing
    //delete struct containing players stats -> betAmt, chipTot, num games, wins, losses
    delete user;
    delete dealer;
    
    return 0;
}

//Create Hand struct containing player's cards info
Hand *hand(){
    int size=10;                //Initialize size of player's hand
    Hand *hand=new Hand;        //Define struct
    hand->cards=new int[size];  //Define cards array
    hand->index=0;              //Initialize index referenced to hand array 
    hand->handTot=0;            //Initalize hand total 
    hand->aceElem=-1;     
    //Set ace element to -1 until ace card pulled
    //when pulled, set aceElem to ace card's index position in cards array
    return hand;                //Return hand struct
}

//Create a Player struct containing players game stats
Player *playr(){
    Player *playr=new Player;   //Define Player struct
    playr->betAmt=0;            //Initalize all members to 0
    playr->chipTot=0;
    playr->games=0;
    playr->wins=0;
    playr->losses=0;
    return playr;               //Return Player struct
}

//Updates players stats and displays a win or loss to user
void stats(Player *playr, Player *dealr){
    if(playr->plyrHnd->handTot>21){ //user goes over, display loss
        //Subtract bet amount from total chips won
        //Chip total can't be negative, set to 0 if chipTot-betAmt < 0
        if(playr->chipTot-playr->betAmt<0)playr->chipTot=0;
        else playr->chipTot-=playr->betAmt;
        playr->games++;     //Increment games played
        playr->losses++;    //Increment losses
        playr->betAmt=0;    //Reset bet amount
        
        //Display stats
        cout<<"You Lose!"<<endl;
        cout<<"Total Chips Won: "<<playr->chipTot<<endl;
    }else if(playr->plyrHnd->handTot<21){
        //If user total and dealer total < 21
        if(dealr->plyrHnd->handTot<21){
            //and user total > dealer total, display win
            if(playr->plyrHnd->handTot>dealr->plyrHnd->handTot){
                playr->chipTot+=playr->betAmt;  //Add bet amount to chip total
                playr->games++; 
                playr->wins++;    //Incrememnt wins
                playr->betAmt=0;
                
                cout<<"You win!"<<endl;
                cout<<"Total Chips Won: "<<playr->chipTot<<endl;
            //user total < dealer total, display loss
            }else{
                if(playr->chipTot-playr->betAmt<0)playr->chipTot=0;
                else playr->chipTot-=playr->betAmt;
                playr->games++;
                playr->losses++;
                playr->betAmt=0;
                
                cout<<"You Lose!"<<endl;
                cout<<"Total Chips Won: "<<playr->chipTot<<endl;
            }
        //user total < 21 and dealer total > 21, display win
        }else if(dealr->plyrHnd->handTot>21){
            playr->chipTot+=playr->betAmt;
            playr->games++;
            playr->wins++;
            playr->betAmt=0;
            
            cout<<"You Win!"<<endl;
            cout<<"Total Chips Won: "<<playr->chipTot<<endl;
        //user total < 21 and dealer total = 21, display loss
        }else{
            if(playr->chipTot-playr->betAmt<0)playr->chipTot=0;
            else playr->chipTot-=playr->betAmt;
            playr->games++;
            playr->losses++;
            playr->betAmt=0;
            
            cout<<"You Lose!"<<endl;
            cout<<"Total Chips Won: "<<playr->chipTot<<endl;
        }
    //User total ==21
    }else{
        //If dealer total != 21, display win
        if(playr->plyrHnd->handTot!=dealr->plyrHnd->handTot){
            playr->chipTot+=playr->betAmt;
            playr->games++;
            playr->wins++;
            playr->betAmt=0;
            
            cout<<"You Win!"<<endl;
            cout<<"Total Chips Won: "<<playr->chipTot<<endl;
        //Dealer total = 21, display loss
        }else{
            if(playr->chipTot-playr->betAmt<0)playr->chipTot=0;
            else playr->chipTot-=playr->betAmt;
            playr->games++;
            playr->losses++;
            playr->betAmt=0;
            
            cout<<"Tie You Lose"<<endl;
            cout<<"Total Chips Won: "<<playr->chipTot<<endl;
        }
    }
}

//Function to allow player to hit while hand total < 21
void hit(Player *playr, char deck[]){
    bool quit=false;    //Set to true when user wants to stop hitting
    //Prompt user to hit while quit is false and hand total < 21
    while(quit==false&&playr->plyrHnd->handTot<21){
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

//Function to check players hand for an ace card (aceElem!=-1)
//If hand total > 21, change the value of ace card to 1
void chckAce(Player *playr){
    //If player has an ace and goes over, set value to 1
    if(playr->plyrHnd->handTot>21&&playr->plyrHnd->aceElem!=-1){
        playr->plyrHnd->cards[playr->plyrHnd->aceElem]=1;
        calcTot(playr);//Recalculate total with ace as 1
    }
}

//Calculate total of players hand
void calcTot(Player *playr){
    int sum=0;      //Variable to hold sum of players hand
    for(int i=0; i<playr->plyrHnd->index;i++)   //Loop through hand
        sum+=playr->plyrHnd->cards[i];          //Add each value in hand to sum
    playr->plyrHnd->handTot=sum;                //Return sum
}

//Create a random number between 0-12 to represent an element in card deck
//Grab the value of card with that element
//convert its value to an integer and store in players hand 
char card(Player *playr, char deck[]){
    int elem=rand()%13; //Element number from 0 to 12
    if(deck[elem]>='2'&&deck[elem]<='9'){
        //Convert the character from deck to its integer equivalent
        playr->plyrHnd->cards[playr->plyrHnd->index]=deck[elem]-48;
    }
    else{
        //If card selected is an ace, record its index in hand array
        //store in aceElem
        if(deck[elem]=='A')playr->plyrHnd->aceElem=playr->plyrHnd->index;
        playr->plyrHnd->cards[playr->plyrHnd->index]=deck[elem]=='A'?11:10;
    }
    playr->plyrHnd->index++;    //Increment index for next card
    return deck[elem];          //Return the card character 
}
