/**
*cpp file of class TestCase
*Author Alexey Titov
*Version 1.0
**/
//library
#include "TestCase.hpp"

//Constructor for TestCase class
TestCase::TestCase(string test_name, ostream &os):successes(0), failures(0), test(test_name), test_count(0),out(os)
{}

//Function that prints num. of successes and num. of failures in testcase.
TestCase& TestCase::print(){
    int num_tests = successes + failures;
    string report = "Test MyStruct operators: "+ to_string(failures) +" failed, "+ to_string(successes) +" passed, "+
    to_string(num_tests) +" total.";
    out<<report<<endl;
    return *this;
}