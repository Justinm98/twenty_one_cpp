/**
 * @author: Justin Maloney
 * @version: 06-23-21
 */

#include <iostream>
#include<limits>
using namespace std;

#include "list.hh"
#include "deck.hh"

static string username;
static Deck deck;
static List<Card*> player_hand;
static List<Card*> dealer_hand;

/**
 * function to prompt user with question and allow user to answer. 
 * checks answer to insure valid input and returns integer relating to
 * option chosen
 * 
 * @PARAM: 
 *      prompt_to_display is the question or prompt to show the user
 *      options is an array to store the options for the user to pick from
 * @RETURN:
 *      returns integer that corresponds to the answer picked
 */
int prompt_user(string prompt_to_display, string options[], int num_of_options){
    
    int answer;
    while(true){
        cout << prompt_to_display << endl;

        for(int i = 0; i < num_of_options; i++){
            cout << (i + 1) << " - " << options[i] << endl;
        }
        
        cin >> answer;
        if(answer > 0 && answer <= num_of_options && !cin.fail()){
            break;
        }
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "invalid input try again..." << endl;
        }
    }

    return answer;
}

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
            else {
                total += 11;
            }
        }
        else {
            total += card->get_value();
        }
        delete card;
        card = player_hand.pop_front();
    }
    
    cout << username << ", your hand total is - " << total << "\n";

    return total;
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
        delete card;
        card = dealer_hand.pop_front();
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

    return total;
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
    cout << "Let the game begin...\n";
    while(true){
        print_player_hand();

        string options[2] = {"hit", "hold"};
        int answer = prompt_user("", options, 2);

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
    game_welcome();
    while(true){
        deal_hands();

        start_main_game_loop();

        string options[2] = {"Yes", "No"};
        int wants_to_quit = prompt_user("Do you want to play again?", options, 2);
             
        if(wants_to_quit == 2){
            break;
        }   
    }
}