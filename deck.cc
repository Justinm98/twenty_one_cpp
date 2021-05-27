/**
 * @Author: Justin Maloney
 * @version: 05-26-21
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <random>
#include <chrono>
using namespace std;

#include "deck.hh"
#include "list.hh"


/**
 * card constructor
 * 
 * @params:
 *      csuit - card suit
 *      crank - card rank
 *      cvalue - card value
 */ 
Card::Card(string csuit, string crank, int cvalue){
    suit = csuit;
    rank = crank;
    value = cvalue;
}

/**
 * prints info statement about card in the format
 * 
 * <rank> of <suit>'s 
 * Value: <value>
 */ 
void Card::print_card(){
    string card_value = to_string(value);
    string name = rank + " of " + suit + "'s\nValue: " + card_value + "\n";
    cout << name;
}

/**
 * Deck constructor calls make_new_deck to instantiate card_deck var
 */ 
Deck::Deck(){
    make_new_deck();
}

/**
 * Deck destructor
 */ 
Deck::~Deck(){
    //TODO
}

/**
 * instantiates card_deck on object declaration, also shuffles deck 
 * 
 * @TODO: Change pseudo random shuffle to better random method 
 */ 
void Deck::make_new_deck(){
    int number_of_suits = 4;
    int number_of_ranks = 13;

    //card attributes
    string suit[4] = {"Heart", "Diamond", "Spade", "Club"};
    string rank[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    
    Card* temp_deck[52]; // temp array to hold newly made cards
    
    int deck_index = 0;
    for(int i = 0; i < number_of_suits; i++){   //outer loop for looping through suits
        for(int j = 0; j < number_of_ranks; j++){   //innder loop for looping through ranks
            if(rank[j] == "Ace"){
                temp_deck[deck_index] = new Card(suit[i], rank[j], 0);
            }
            else if(rank[j] == "King" || rank[j] == "Queen" || rank[j] == "Jack"){
                temp_deck[deck_index] = new Card(suit[i], rank[j], 10);
            }
            else{
                temp_deck[deck_index] = new Card(suit[i], rank[j], j + 1);
            }
            deck_index++;
        }   //end inner loop
    }   //end out loop
    
    //shuffle deck
    random_shuffle(begin(temp_deck), end(temp_deck));

    //add cards to card_deck linked list
    for(int i = 0; i < 52; i++){
        card_deck.push_front(temp_deck[i]);
    }
}

/**
 * pops card from card_deck linked list
 * 
 * @RETURNS:
 *  returns card popped from head of card_deck deck
 */ 
Card* Deck::deal_card(){
    if(!card_deck.is_empty()){
        Card *card_to_deal = card_deck.pop_front();
        return card_to_deal;
    }
    cout << "NULL\n";
    return NULL;
}