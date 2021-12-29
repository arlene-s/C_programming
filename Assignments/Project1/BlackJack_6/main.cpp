/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on November 3, 2021, 8:00 PM
 * Purpose:  Sixth version of black jack game
 *           -Write user structure to binary file
 *              -Write number of games played to file
 *              -Total Wins
 *              -Total Losses
 *              -Total Chips Won
 *           -Read from binary file into user struct and display stats
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <ctime>
#include <iomanip>
#include <fstream>
#include <valarray>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
struct Card{             //Structure representing a single card from deck
    string face;         //Each card contains a face
    char suit;           //and suit
    int val;             //Variable holding corresponding value of card
};

struct Hand{             //Structure containing players hand details
    int *cards;          //Array holding players hand
    int index;           //Current index/size of array
    int handTot;         //Current sum of players hand
    int aceElem;         //Ace card index, val to change when total>21
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
Hand *hand(int);                 //Returns a Hand struct with initialized values
string card(Player *, Card []);  //Assigns card to player
void calcTot(Player *);          //Calculate total of hand
void hit(Player *, Card []);     //Ask user if want another card
void stats(Player *, Player *);  //Display win or loss
void chckAce(Player *);          //Check if players hand contains an ace
void shuffle(Card []);           //Passes in deck and shuffles values in deck
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    int size;                    //Size of player's hand
    char input;                  //User input to play game again (y/n)
    fstream binFile;             //Binary file
    
    //Initialize variables here
    size=10;                     //Initialize hand size to 10, too big
    Player *user=playr();        //Create a player struct for user
    Player *dealer=playr();      //Create a player struct for dealer
    //Static array to hold face of each card
    string faces[]={"2","3","4","5","6","7","8","9","10","J","K","Q","A"};
    //Static array to hold suit of each card
    char suits[]={'D','C','H','S'};
    //Static array to hold corresponding face value
    int cardVals[]={2,3,4,5,6,7,8,9,10,10,10,10,11};
    Card deck[52];  //Define an array of structures, each element a Card struct
    
    //Create deck of cards
    int k=0;
    for(int i=0; i<4;i++){     
        for(int j=0; j<13;j++){
            deck[k].face=faces[j];  //Assign a face to card
            deck[k].suit=suits[i];  //Assign a suit
            deck[k].val=cardVals[j];//Assign the face value
            k++;                    //Increment, k goes to 52 (size of deck array)
        }
    }
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Play Blackjack!"<<endl;
    cout<<"Beat the dealer by gaining a hand total close to 21 without going over. "<<endl
        <<"If you have an ace card, its value is 11 until you go over 21. When "
        <<"you go over, your ace will change to 1 and you can continue hitting "
        <<"until you go over again."<<endl
        <<"Min bet: $20"<<endl<<"Max bet: $100"<<endl;
    
    binFile.open("stats.bin",ios::out|ios::binary);
    do{
        cout<<"--------------------------------------"<<endl;
        user->plyrHnd=hand(size);    //Allocate memory to hand info struct
        dealer->plyrHnd=hand(size);      
        cout<<"Place your bet: ";
        cin>>user->betAmt;           //Collect users bet amount
        //Error check, amount cant be less than 20 or greater than 100
        while(user->betAmt<20 || user->betAmt>100){
            cout<<"Invalid bet amount"<<endl;
            cout<<"Min: $20 "<<"Max: $100"<<endl;
            cin>>user->betAmt;
        }
        
        shuffle(deck);               //Shuffle the deck
        //Pull cards and display them
        cout<<"Your cards: "<<card(user, deck)<<" "<<card(user, deck)<<endl;
        calcTot(user);               //Calculate total of hand
        chckAce(user);               //Check if ace card pulled, if went over change val to 1
        //Display users total
        cout<<"Total: "<<user->plyrHnd->handTot<<endl<<endl;

        cout<<"Dealers first card: "<<card(dealer,deck)<<endl;
        //If users hand total < 21, call function to prompt user to hit
        //prompt user while total<21 and until they want to stop
        if(user->plyrHnd->handTot<21){
            hit(user, deck);
            cout<<"Total: "<<user->plyrHnd->handTot<<endl<<endl;
        }

        //Grab second card for dealer
        cout<<"Dealers second card: "<<card(dealer,deck)<<endl;
        calcTot(dealer);             //Calculate the dealers hand total
        while(dealer->plyrHnd->handTot<17){//Dealer pulls cards until the total is 17 or greater
            cout<<"Dealer hits: "<<card(dealer,deck)<<endl;
            calcTot(dealer);         //Calculate new total
            chckAce(dealer);         //Check if card pulled is an ace
        }
        //Display dealers total
        cout<<"Dealers total: "<<dealer->plyrHnd->handTot<<endl<<endl;

        //Display the results
        stats(user, dealer);         //Compare user and dealer totals and display win or loss
        
        //Deallocate memory
        //Delete only the player's hand info inside do while loop to reset their hand
        //but keep players stats -> betAmt, chipTot, num games, wins, losses
        delete []user->plyrHnd->cards;      //Destroy users hand, hand total, and size
        delete user->plyrHnd;               //Destroy Hand structure
        delete []dealer->plyrHnd->cards;    
        delete dealer->plyrHnd;
        
        binFile.write(reinterpret_cast<char *>(user),sizeof(user));
        
        //Prompt user for next game or to end game
        cout<<"Would you like to play again? (y/n) ";
        cin>>input;
        //If input uppercase, convert to lowercase
        //User can only enter 'y' or 'n', loop while input invalid
        while(tolower(input)!='y'&&tolower(input)!='n'){
            cout<<"Invalid please enter 'y' or 'n"<<endl;
            cin>>input;
        }
    }while(tolower(input)=='y');     //Start game again if input == 'y'
    
    binFile.close();
    //End of game, display other stats
    //Open binary file for output
    binFile.open("Stats.bin",ios::in|ios::binary);

    //If file open successful, read from beginning of file
    if(binFile){
        //Store input from file back into user struct
        //Display stats
        binFile.read(reinterpret_cast<char *>(user),sizeof(user));
        cout<<"***************************************"<<endl;
        while(!binFile.eof()){
            cout<<"Game #: "<<user->games<<endl;
            cout<<"Bet Amount: "<<user->betAmt<<endl;
            cout<<"Chips Won: "<<user->chipTot<<endl;
            cout<<"***************************************"<<endl;
            binFile.read(reinterpret_cast<char *>(user),sizeof(user));
        }
        //Close file
        binFile.close();
    }else{
        cout<<"Error opening file"<<endl;
    }
    
    //Deallocate memory
    //Now when user is done playing
    //delete struct containing players stats -> betAmt, chipTot, num games, wins, losses
    delete user;
    delete dealer;
    
    return 0;
}

//Create Hand struct containing player's cards info
Hand *hand(int n){
    n=n<2?2:n;                  //Initialize size of player's hand
    Hand *hand=new Hand;        //Define struct
    hand->cards=new int[n];  //Define cards array
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
void hit(Player *playr, Card deck[]){
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

//Modified to return string instead of char
//Create a random number between 0-51 to represent an element in card deck
//Store the value of face card from deck into players hand
string card(Player *playr, Card deck[]){
    int elem=rand()%52;         //Element number from 0 to 12
    //Store the value of face card from deck into players hand
    playr->plyrHnd->cards[playr->plyrHnd->index]=deck[elem].val;
    //If card selected is an ace, record its index in hand array
    if(deck[elem].face=="A")playr->plyrHnd->aceElem=playr->plyrHnd->index;
    playr->plyrHnd->index++;    //Increment index for next card
    //Return face card and suit
    return deck[elem].face+deck[elem].suit;
}

//Function shuffles deck by using a random number to grab a face from deck
//and swap it with deck[i] 
void shuffle(Card deck[]){
    Card temp;                 //Create a temp card to store face card contents
    int r;                     //Store random number
    for(int i=0;i<52;i++){
        r=rand()%52;           //Grab random number
        temp=deck[i];          //Store face card in temp card
        deck[i]=deck[r];       //Change face card in deck to random face card in deck
        deck[r]=temp;          //Swap random face card with temp
    }
}