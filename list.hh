/**
 * @Author: Justin Maloney
 * @version: 05-26-21
 */

// list.hh
#ifndef _LIST_H
#define _LIST_H

/**
 * node struct for singly linked list
 */ 
template <typename T>
struct Node {
    T value; 
    Node<T>* next; //pointer to next node in list
};


/**
 * simple singly linked list class
 * 
 * Utilizes a sentinel head node to store list start.
 * Support Generic types.
 * Supports LIFO functionality
 * 
 * @TODO: make destuctor
 */ 
template <typename T>
class List {      
    private:
        int size;   //link list size
        Node<T>* head;  //sentinel head node to store list start
    public:
        List(); //default constructor
        ~List();
        void push_front(T new_value);    //push node to the front of list
        Node<T>* list_begin(void);    //push node to the front of list
        Node<T>* list_next(Node<T>* node);    //push node to the front of list
        T pop_front();  //pops node off the front of the list
        bool is_empty(); //checks if list is empty
};

#endif