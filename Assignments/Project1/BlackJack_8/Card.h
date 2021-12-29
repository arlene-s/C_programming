/* 
 * File:   Card.h
 * Author: Arlene Sagaoinit
 * Created on November 14, 2021, 6:38 PM
 * Purpose: Structure holding info of a single card from deck
 *          -face of card
 *          -suit of card
 *          -corresponding value of face
 */

#ifndef CARD_H
#define CARD_H

struct Card{             //Structure representing a single card from deck
    string face;         //Each card contains a face
    char suit;           //and suit
    int val;             //Variable holding corresponding value of card
};


#endif /* CARD_H */

