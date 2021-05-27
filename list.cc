/**
 * @Author: Justin Maloney
 * @version: 05-26-21
 */

#include <iostream>
using namespace std;

#include "list.hh"
#include "deck.hh"

/**
 * List constructor
 */ 
template <typename T>
List<T>::List(){
    size = 0;
    head = new Node<T>;
    head->next = NULL;
}

/**
 * List constructor
 */ 
template <typename T>
List<T>::~List(){
    if(!is_empty()){
        while(!is_empty()){
            Card* card = pop_front();
            delete card;
        }
    }
    
    delete head;
}

/**
 * pushes node to the front of the list.
 * Inserts new node right behind head
 */ 
template <typename T>
void List<T>::push_front(T new_value) {
    Node<T> *temp = head->next;
    Node<T> *new_node = new Node<T>;
    head->next = new_node;
    new_node->next = temp;
    new_node->value = new_value;
    size++;
}

/**
 * pops node off the front of the list
 * 
 * @RETURNS:
 *  returns node value
 */ 
template <typename T>
T List<T>::pop_front() {
    Node<T>* temp = head->next;
    head->next = temp->next;
    size--;
    T value = temp->value;
    delete temp;
    return value;
}

/**
 * checks if list is empty using size variable
 */ 
template <typename T>
bool List<T>::is_empty(){
    return size == 0;
}

//list class declaration to support Card* objects
template class List<Card*>;