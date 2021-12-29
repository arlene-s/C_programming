/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on October 25, 2021, 3:16 PM
 * Purpose: Pseudocode for black jack card game
 *          -Contains pseudocode for a single game play
 *          -Uses random number generator
 *          -Includes static array to represent face cards
 *          -Includes static arrays for each players hand
 */

//System libraries
#include <iostream> //Input/output library
using namespace std;

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

int main(int argc, char** argv) {
    //Include libraries: iostream, ctime
    //Create random number generator srand(static_cast<unsigned int>(time(0)))
    //Create char array holding face cards
    //char cards[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'}
    
    //Initialize values
    //Create player and dealers hand arrays
    // set size of hand to 10
    // set playIdx of hand to 0
    // set dealIdx of hand to 0
    // int player[size]
    // int dealer[size]
    
    //Grab a face card from cards[] place in player[playIdx]
    // if card between '2' and '9'
    //      convert to int cards[rand()%13]-48;
    //      set player[playIdx]=cards[rand()%13]-48;
    // else card is either 'T','J','Q','K','A'
    //      if card is 'A'
    //          set player[playIdx]=11;
    //      else card is 'T','J','Q','K'
    //          set player[playIdx]=10;
    // increment playIdx

    //Assign a second card to player (repeat above step)

    //Assign a card to dealer
    //Grab a face card from cards[] place in dealer[dealIdx]
    // if card between '2' and '9'
    //      convert to int cards[rand()%13]-48;
    //      set dealer[dealIdx]=cards[rand()%13]-48;
    // else card is either 'T','J','Q','K','A'
    //      if card is 'A'
    //          set dealer[dealIdx]=11;
    //      else card is 'T','J','Q','K'
    //          set dealer[dealIdx]=10;
    // increment dealIdx

    //Map outputs
    //Calculate total of player and dealers hand
    // set playTot to 0
    // loop from index 0 to playIdx, index++
    //      Add player[index] to playTot
    // set dealTot to 0
    // loop from index 0 to dealIdx, index++
    //      Add dealer[index] to dealTot

    //If player total < 21 prompt player to hit or stay
    // set bool quit to false
    // define char hit;
    // while playTot < 21 && quit is false
    //      cout "Hit?"
    //      Assign input to hit variable
    //      if hit == 'y'
    //          assign card to player[playIdx]
    //          calculate total
    //      else hit == 'n'
    //          set quit to true

    //Display results
    //Compare totals and display win or loss
    // if playTot > 21
    //      cout "loser"
    // else if playTot < 21
    //      if dealTot < 21 
    //          if playTot > dealTot
    //              cout "winner"
    //          else playTot < or equal to dealTot
    //              cout "loser"
    //      else if  dealTot > 21
    //          cout "winner"
    //      else dealTot==21
    //          cout "loser"
    //else playTot == 21
    //      if dealTot!= 21
    //          cout "Black jack!"
    //      else dealTot =21
    //          cout "Tie! loser" 
        
    
    return 0;
}

