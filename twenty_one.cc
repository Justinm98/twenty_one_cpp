/**
 * @Author: Justin Maloney
 * @version: 05-26-21
 */

#include <iostream>
using namespace std;

#include "list.hh"
#include "deck.hh"

/**
 * Temp code to test deck creation and shuffling
 */ 
int main(){
    Deck deck;  //make game deck 
    
    //loop through deck and draw all cards
    for(int i = 0; i < 52; i++){
        Card* card = deck.deal_card();  //deal card
        if(card != NULL){
            card->print_card(); //print card 
            delete card;
        }
        else{
            cout << "Card was NULL\n";
        }
    }
    return 0;
}
