/**
 * @author: Justin Maloney
 * @version: 05-26-21
 */

// deck.hh
#ifndef DECK_H
#define DECK_H
#include <iostream>
using namespace std;

#include "list.hh"

/**
 * card class to store card suit, rank, and value
 */ 
class Card {
    private:
        string suit;
        string rank;
        int value;
    public:
        Card(string csuit, string crank, int cvalue);   //constructor
        ~Card();   //destructor
        string get_suit(void);
        string get_rank(void);
        int get_value(void);
        void print_card_value(void);  //print card
        void print_card_graphic(void);
};

/**
 * deck class to store 52 card deck for card games
 */
class Deck {
    private:
        List<Card*> card_deck; //list object to represent deck
        void make_new_deck();   //deck instantiation method
    public:
        Deck(); //default constructor to instantiate deck
        ~Deck();
        Card* deal_card();  //deal card from card_deck
};

#endif