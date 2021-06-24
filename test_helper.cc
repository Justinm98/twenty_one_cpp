/**
 * @author: Justin Maloney
 * @version: 06-24-21
 */

#include <iostream>
using namespace std;

/**
 * test function to check boolean condition for true to assist in testing.
 * prints test name and PASSED for true condition and FAILED for false condition
 * 
 * @PARAMS:
 *      test_name is the name of the test to print 
 *      condition is the bool outcome to check for true
 */ 
void test_condition(string test_name, bool condition){
    if(condition){
        cout << test_name << " - PASSED" << endl;
    }else{
        cout << test_name << " - FAILED" << endl;
    }
}


/**
 * test function to check for equality of value between two variables.
 * prints test name and PASSED for if values are equal and FAILED if not
 * 
 * @PARAM:
 *      test_name is the name of the test to print 
 *      value_one and value_two are the values to compare
 */ 
template <typename T>
void test_equals(string test_name, T value_one, T value_two){
    if(value_one == value_two){
        cout << test_name << " - PASSED";
    }else{
        cout << test_name << " - FAILED";
    }
}