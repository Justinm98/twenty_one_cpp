#ifndef _TEST_HELPER_H
#define _TEST_HELPER_H

#include <iostream>
using namespace std;

/**
 * function to test condition for true
 */ 
void test_condition(string test_name, bool condition);

/**
 * function to test whether two variables are equal
 */ 
template <typename T>
void test_equals(string test_name, T value_one, T value_two);

#endif