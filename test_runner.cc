/**
 * @author: Justin Maloney
 * @version: 06-25-21
 */

#include <iostream>
using namespace std;

#include "test_list.hh"
#include "test_deck.hh"

int main(){
    cout << "Testing list class-" << endl;
    test_push_front();
    test_pop_front();
    test_list_begin();
    test_list_next();
    test_is_empty();
    cout << endl;

    cout << "Testing deck class-" << endl;
    test_get_suit();
    test_get_rank();
    test_get_value();
    test_print_card_value();
    test_print_card_graphic();
    test_make_new_deck();
    test_deal_card();
    cout << endl;
}