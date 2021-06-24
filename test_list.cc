/**
 * @author: Justin Maloney
 * @version: 06-24-21
 */

#include <iostream>
using namespace std;

#include "test_helper.hh"
#include "list.hh"

void test_push_front(){
    List<int> list;

    list.push_front(1);
    int size = list.get_size();
    test_condition("list size is one", size == 1);

    list.push_front(1);
    size = list.get_size();
    test_condition("list size is two", size == 2);
}

void test_pop_front(){
    List<int> list;

    list.push_front(1);
    list.push_front(1);
    int size = list.get_size();
    test_condition("list size is one", size == 2);

    list.pop_front();
    size = list.get_size();
    test_condition("list size is one", size == 1);

    list.pop_front();
    size = list.get_size();
    test_condition("list size is one", size == 0);
}

void test_list_begin(){
    List<int> list;

    list.push_front(1);
    Node<int> *node = list.list_begin();
    int value = node->value;
    test_condition("head node is 1", value == 1);

    list.push_front(11);
    node = list.list_begin();
    value = node->value;
    test_condition("head node is 11", value == 11);

    list.pop_front();
    node = list.list_begin();
    value = node->value;
    test_condition("head node is 1 after pop", value == 1);
}

void test_list_next(){
    List<int> list;

    list.push_front(1);
    list.push_front(2);
    Node<int> *node = list.list_begin();
    int value = node->value;
    test_condition("head node is 2", value == 2);

    node = list.list_next(node);
    value = node->value;
    test_condition("head node is 1", value == 1);
}

void test_is_empty(){
    List<int> list;
    bool list_is_empty = list.is_empty();
    test_condition("empty list test", list_is_empty);

    list.push_front(1);
    bool list_is_not_empty = !(list.is_empty());
    test_condition("not empty list test", list_is_not_empty);

    list.pop_front();
    list_is_not_empty = list.is_empty();
    test_condition("empty list after pop test", list_is_not_empty);
}