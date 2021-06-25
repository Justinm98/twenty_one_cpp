/**
 * @author: Justin Maloney
 * @version: 06-25-21
 */

#include <iostream>
#include <sstream>
using namespace std;

#include "test_helper.hh"
#include "deck.hh"

void test_get_suit(){
    Card *card = new Card("Heart", "A", 0);
    test_condition("get suit test", card->get_suit() == "Heart");
}

void test_get_rank(){
    Card *card = new Card("Heart", "A", 0);
    test_condition("get suit test", card->get_rank() == "A");
}

void test_get_value(){
    Card *card = new Card("Heart", "A", 0);
    test_condition("get rank test", card->get_rank() == "A");
}

void test_print_card_value(){
    Card *card = new Card("Heart", "A", 0);

    streambuf* original_stdout = cout.rdbuf();
    ostringstream stdout_output;
    cout.rdbuf(stdout_output.rdbuf());

    card->print_card_value();

    cout.rdbuf(original_stdout);
    test_condition("print card value test", stdout_output.str() == "A of Hearts\nValue: 0\n");
}

void test_print_card_graphic(){
    Card *card = new Card("Heart", "A", 0);

    streambuf* original_stdout = cout.rdbuf();
    ostringstream stdout_output;
    cout.rdbuf(stdout_output.rdbuf());

    card->print_card_graphic();
    string card_graphic = ".------.\n";
    card_graphic += "|A.--. |\n";
    card_graphic += "| (\\/) |\n";
    card_graphic += "| :\\/: |\n";
    card_graphic += "| '--'A|\n";
    card_graphic += "`------'\n";

    cout.rdbuf(original_stdout);
    test_condition("print card graphic test", stdout_output.str() == card_graphic);
}

void test_make_new_deck(){
    Deck deck;
    Card* card = deck.deal_card();
    int card_count = 1;
    delete card;

    while(card != NULL){
        card = deck.deal_card();
        card_count++;
        delete card;
    }
    card_count--;

    test_condition("make new deck test", card_count == 52);
}

void test_deal_card(){
    Deck deck;

    Card* card = deck.deal_card();
    test_condition("deal card test", card != NULL);

    string suit = card->get_suit();
    string rank = card->get_rank();
    int value = card->get_value();

    test_condition("dealt card suit test", suit != "");
    test_condition("dealt card rank test", rank != "");
    test_condition("dealt card value test", value > -1);
}