/**
 * @Author: Justin Maloney
 * @version: 05-26-21
 */

#include <iostream>
using namespace std;

#include "list.hh"
#include "deck.hh"

static string username;
static Deck deck;
static List<Card*> player_hand;
static List<Card*> dealer_hand;

/**
 * welcome function to welcome user to game and get user's username
 */ 
void game_welcome(){
    cout << "Welcome to ...\n";
    cout << " ___    __  .------..------." << "\n";
    cout << "|__ \\  /_ | |2.--. ||1.--. |" << "\n";
    cout << "   ) |  | | | (\\/) || :/\\: |" << "\n";
    cout << "  / /   | | | :\\/: || (__) |" << "\n";
    cout << " / /_   | | | '--'2|| '--'1|" << "\n";
    cout << "|____|  |_| `------'`------'" << "\n";
    cout << "\n";
    cout << "Enter your Username: ";
    cin >> username;
}

/**
 * function to deal hands for dealer and player.
 * 
 * Draws two cards for dealer and player
 */ 
void deal_hands(){
    Card *card_one = deck.deal_card();
    Card *card_two = deck.deal_card();
    Card *card_three = deck.deal_card();
    Card *card_four = deck.deal_card();

    player_hand.push_front(card_one);
    player_hand.push_front(card_two);
    dealer_hand.push_front(card_three);
    dealer_hand.push_front(card_four);
}

/**
 * displays player hand using ascii card graphic
 */ 
void print_player_hand(){
    cout << username << ", your hand contains...\n";
    for(Node<Card*>* card = player_hand.list_begin();
        card != NULL;
        card = player_hand.list_next(card)){
        card->value->print_card_graphic();
    }
}

/**
 * displays dealer hand using ascii card graphic
 */
void print_dealer_hand(){
    cout << "The dealer's hand contains...\n";
    for(Node<Card*>* card = dealer_hand.list_begin();
        card != NULL;
        card = dealer_hand.list_next(card)){
        card->value->print_card_graphic();
    }
}

/**
 * function to calculate players hand total.
 * 
 * prompts user to select what value they want for Ace's
 * and returns hand total.
 */ 
int get_total_player_hand(){
    int total = 0;
    Card* card = player_hand.pop_front();
    while(card != NULL){
        if(card->get_rank() == "A"){
            int answer;
            while(true){
                cout << "What value should your Ace count as?\n1 - 1\n2 - 11\n";
                cin >> answer;
                if(answer == 1 || answer == 2){
                    break;
                }
                else{
                    cout << "invalid input try again\n";
                }
            }

            if(answer == 1){
                total += 1;
            }
            else{
                total += 11;
            }
        }
        else{
            total += card->get_value();
        }
    }
    cout << username << ", your hand total is - " << total << "\n";
}

/**
 * function to calculate dealer's hand total
 * 
 * simple algorithm to select 1 or 11 for aces.
 */ 
int get_total_dealer_hand(){
    int total = 0;
    int number_of_aces = 0;
    Card* card = dealer_hand.pop_front();
    while(card != NULL){
        if(card->get_rank() == "A"){
            number_of_aces++;
        }
        else{
            total += card->get_value();
        }
    }

    for(int i = 0; i < number_of_aces; i++){
        int total_with_eleven = total + 11;
        int total_with_one = total + 1;
        if(total_with_eleven <= 21){
            total += 11;
        }
        else if(total_with_one <= 21){
            total += 1;
        }
        else{
            total += 1;
        }
    }

    cout << "The Dealer's total is - " << total << "\n";
}

/**
 * check's player and dealer hand total and displays result
 */ 
void check_win_condition(int player_total, int dealer_total){
    if(player_total > 21){
        cout << "OH NO! Your total went over 21! BUST!\nDealer wins!";
    }
    else{
        int player_diff = 21 - player_total;
        int dealer_diff = 21 - dealer_total;
        if(dealer_diff == player_diff){
            cout << "You and the dealer have the same total! TIE!";
        }
        else if(player_diff < dealer_total){
            cout << username << ", YOU WIN! Dealer lost.\n";
        }
        else{
            cout << username << ", YOU LOST! Dealer wins.\n";
        }
    }
}

/**
 * function to control the flow of the game 21.
 * 
 * Simulates prompts from the dealer like hit or hold
 * and will determine who won.
 */ 
void start_main_game_loop(){
    cout << "Let the game begin...";
    while(true){
        print_player_hand();

        int answer;
        while(true){
            cout << "Do you want to hit or hold?\n1 - hit\n2 - hold\n";
            
            cin >> answer;
            if(answer == 1 || answer == 2){
                break;
            }
        }

        if(answer == 1){
            Card *card = deck.deal_card();
            player_hand.push_front(card);
            cout << "Card dealt to player\n";
        }
        else{
            int player_total = get_total_player_hand();
            int dealer_total = get_total_dealer_hand();

            check_win_condition(player_total, dealer_total);
            break;
        }
    }
}

/**
 * Temp code to test deck creation and shuffling
 */ 
int main(){
    while(true){
        game_welcome();
        deal_hands();

        start_main_game_loop();
        bool wants_to_quit;
        while(true){
            cout << "Do you want to play again?\n1 - Yes\n2 - No\n";
            int answer;
            cin >> answer;
            if(answer == 1 || answer == 2){
                wants_to_quit = true;
            }
            else{
                cout << "invalid input try again...";
            }
        }

        if(wants_to_quit){
            break;
        }
    }
}