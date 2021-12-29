/* 
 * File:   Player.h
 * Author: Arlene Sagaoinit
 * Created on November 14, 2021, 6:41 PM
 * Purpose: Structure holding players gameplay stats
 *          -Nested structure, pointer to Hand struct to hold players hand
 *          -Bet amount
 *          -Chips collected each round, resets each round
 *          -Total chips collected for whole gameplay
 *          -Number of games
 *          -Number of wins
 *          -Number of losses
 *          -Status for win or loss, win=true;
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Hand.h"

class Player{
    private:
        Hand *plyrHnd;
        int betAmt;
        int chipsWon;
        int totChips;
        unsigned int games;
        unsigned int wins;
        unsigned int losses;
        bool status;
    public:
        Player(){
        }
        void setHand(Hand *hand){
            plyrHnd=hand;
        }
        void setBet(int bet){
            betAmt=bet;
        }
        void setChips(int chips){
            chipsWon=chips;
        }
        void setTot(int total){
            totChips=total;
        }
        void setGames(unsigned int g){
            games=g;
        }
        void setWins(unsigned int w){
            wins=w;
        }
        void setLoss(unsigned int loss){
            losses=loss;
        }
        void setStatus(bool stat){
            status=stat;
        }
        bool getStatus(){
            return status;
        }
        
        int getBet(){
            return betAmt;
        }
        
        unsigned int nGames(){
            return games;
        }
        
        int getChips(){
            return chipsWon;
        }
        
        unsigned int getWins(){
            return wins;
        }
        
        unsigned int getLosses(){
            return losses;
        }
        
        int getTot(){
            return totChips;
        }
        
        void stats(Player *dealr){
            if(plyrHnd->total()>21){ //user goes over, display loss
                //Subtract bet amount from total chips won
                //totChips can't be negative, set to 0 if totChips-betAmt < 0
                if(totChips-betAmt<0)totChips=0;
                else totChips-=betAmt;
                games++;     //Increment games played
                losses++;    //Increment losses
                status=false;    //Status false for loss

                //Display stats
                cout<<"You Lose!"<<endl;
                cout<<"Chips Won: "<<chipsWon<<endl;
            }else if(plyrHnd->total()<21){
                //If user total and dealer total < 21
                if(dealr->plyrHnd->total()<21){
                    //and user total > dealer total, display win
                    if(plyrHnd->total()>dealr->plyrHnd->total()){
                        totChips+=betAmt;  //Add bet amount to chip total
                        chipsWon+=betAmt;
                        games++; 
                        wins++;          //Incrememnt wins
                        status=true;     //True for win

                        cout<<"You win!"<<endl;
                        cout<<"Chips Won: "<<chipsWon<<endl;
                    //user total < dealer total, display loss
                    }else{
                        if(totChips-betAmt<0)totChips=0;
                        else totChips-=betAmt;
                        games++;
                        losses++;
                        status=false;

                        cout<<"You Lose!"<<endl;
                        cout<<"Chips Won: "<<chipsWon<<endl;
                    }
                //user total < 21 and dealer total > 21, display win
                }else if(dealr->plyrHnd->total()>21){
                    totChips+=betAmt;
                    chipsWon+=betAmt;
                    games++;
                    wins++;
                    status=true;

                    cout<<"You Win!"<<endl;
                    cout<<"Chips Won: "<<chipsWon<<endl;
                //user total < 21 and dealer total = 21, display loss
                }else{
                    if(totChips-betAmt<0)totChips=0;
                    else totChips-=betAmt;
                    games++;
                    losses++;
                    status=false;

                    cout<<"You Lose!"<<endl;
                    cout<<"Chips Won: "<<chipsWon<<endl;
                }
            //User total ==21
            }else{
                //If dealer total != 21, display win
                if(plyrHnd->total()!=dealr->plyrHnd->total()){
                    totChips+=-betAmt;
                    chipsWon+=betAmt;
                    games++;
                    wins++;
                    status=true;

                    cout<<"You Win!"<<endl;
                    cout<<"Chips Won: "<<chipsWon<<endl;
                //Dealer total = 21, display loss
                }else{
                    if(totChips-betAmt<0)totChips=0;
                    else totChips-=betAmt;
                    games++;
                    losses++;
                    status=false;

                    cout<<"Tie You Lose"<<endl;
                    cout<<"Chips Won: "<<chipsWon<<endl;
                }
            }
        }
};

#endif /* PLAYER_H */