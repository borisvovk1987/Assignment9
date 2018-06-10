#pragma once
/**
*header file of class TestCase
*Authors Alexey Titov and Shir Bentabou
*Version 1.0
**/
//libraries
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <functional>
using namespace std;


class TestCase{
    private:
        string test;
        ostream &out;
        int successes;
        int failures;
        int test_count;

    public:
        //Constructor for TestCase class
        TestCase(string test_name, ostream &os);
        //Function that compares between two objects.
        template <typename T1, typename T2>
        TestCase& check_equal(T1 a, T2 b){
            this->test_count++;
            if (a==b){
                this->successes++;
                return *this;
            }
            this->failures++;
            ostringstream stream1;
            stream1 << a;
            ostringstream stream2;
            stream2 << b;
            string ans = this->test+": Failure in test #"+to_string(this->test_count)+": "+stream1.str()+
                        " should equal "+stream2.str()+"!";
            out<<ans<<endl;
            return *this;
        }

        //Function that checks if two objects are different.
        template <typename T1, typename T2>
        TestCase& check_different(T1 a, T2 b){
            test_count++;
            if (a!=b){
                successes++;
                return *this;
            }
            failures++;
            ostringstream stream1;
            stream1 << a;
            ostringstream stream2;
            stream2 << b;
            string ans = test+": Failure in test #"+to_string(test_count)+": "+stream1.str()+
                        " should not equal "+stream2.str()+"!";
            out<<ans<<endl;
            return *this;
        }

        //Function that compares the ostream compared to a given string.
        template <typename T>
        TestCase& check_output(T a, string s){
            test_count++;
            ostringstream stream;
            stream << a;
            string str = stream.str();
            if (str.compare(s)==0){
                successes++;
                return *this;
            }
            failures++;
            string ans = test+": Failure in test #"+to_string(test_count)+": string value should be " + s +
                        " but is "+ str;
            out<<ans<<endl;
            return *this;
        }

        //Function that receives a function, and two variables, and compares the between the answer received from the function
        //and the answer already known.
        template <typename Func,typename Rec, typename Ans>
        TestCase& check_function(Func function_name, Rec received, Ans answered){
            test_count++;
            Ans a = function_name(received);
            if (a==answered){
                successes++;
                return *this;
            }
            failures++;
            ostringstream stream1;
            stream1 << a; //what the function returns
            ostringstream stream2;
            stream2 << answered; //the real answer we are supposed to received
            string str = test+": Failure in test #"+to_string(test_count)+": Function should return "+stream2.str()+
                        " but returned "+stream1.str()+"!";
            out<<str<<endl;
            return *this;
        }
        //Function that prints num. of successes and num. of failures in testcase.
        TestCase& print();
};