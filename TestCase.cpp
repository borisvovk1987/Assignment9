#include "TestCase.hpp"


TestCase::TestCase(string testName, ostream &out):passedTests(0), failedTests(0), testName(testName), totalTests(0),out(out)
{}

TestCase& TestCase::print(){

    out<<testName<<": "<<failedTests<<" failed, "<<passedTests<<" passed, "<<totalTests<<" total.\n";
    return *this;
}
