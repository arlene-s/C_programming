/* 
 * File:   main.cpp
 * Author: arlen
 *
 * Created on December 13, 2021, 12:35 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Deck.h"
#include "Hand.h"

int main(int argc, char** argv) {
    int deckSize=52;
    int handSize=10;
    int index=0;
    Deck cardDeck(deckSize);
    
    for(int i=0; i<deckSize;i++){
        cout<<i<<": "<<cardDeck.face(i)<<" "<<cardDeck.suit(i)<<" "
            <<cardDeck.val(i)<<endl;
    }
    
    cardDeck.shuffle();
    cout<<endl;
    for(int i=0; i<deckSize;i++){
        cout<<i<<": "<<cardDeck.face(i)<<" "<<cardDeck.suit(i)<<" "
            <<cardDeck.val(i)<<endl;
    }
    
    Hand hand(handSize);
    cout<<"Card 1: "<<hand.dealCrd(cardDeck, index)<<hand.dealCrd(cardDeck, index)<<endl;
    
    
    return 0;
}

