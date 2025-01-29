#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"

#include "Kolmakov_MathTask.h"

using namespace cute;

void testCalcSum()
{
    double x = 2.1;
    double y = 3.2;
    double z = 4.2;
    double expected = 9;

    double actual = CalcIntSumPart(x, y, z);

    ASSERT_EQUAL(expected, actual);
}


void testCalcAvg()
{
    double x = -3.6;
    double y = 6.9;
    double z = 18.2;
    double expected = 0.674928292114747;

    double actual = CalcFractPart(x, y, z);

    ASSERT_EQUAL(expected, actual);
}

void testUserInput_Empty(){
    string str = "";

    bool expected = false;
    bool actual = UserInput(str);

    ASSERT_EQUAL(expected, actual);
}

void testUserInput_Letter(){
    string str = "a";

    bool expected = false;
    bool actual = UserInput(str);

    ASSERT_EQUAL(expected, actual);
}


void testUserInput_UncorrectValue(){
    string str = "five5";

    bool expected = false;
    bool actual = UserInput(str);

    ASSERT_EQUAL(expected, actual);
}



int main(){
    suite s;

    s.push_back(CUTE(testCalcSum));
    s.push_back(CUTE(testCalcAvg));
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_UncorrectValue));

    ide_listener<> listener;
    makeRunner(listener)(s, "All Tests");

    return 0;
}