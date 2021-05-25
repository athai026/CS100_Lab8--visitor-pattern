#ifndef __MULTTEST_HPP__
#define __MULTTEST_HPP__

#include <string>
#include "gtest/gtest.h"
#include "VisitorLaTeX.hpp"
#include "mult.hpp"
#include "op.hpp"

TEST(VisitorMultTest, Ten_times_Five) {
    Base* op1 = new Op(10);
    Base* op2 = new Op(5);
    Base* mult = new Mult(op1, op2);
    std::string result = "${({10}\\cdot{5})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(mult), result);
}

TEST(VisitorMultTest, Six_times_Nine) {
    Base* op1 = new Op(6);
    Base* op2 = new Op(9);
    Base* mult = new Mult(op1, op2);
    std::string result = "${({6}\\cdot{9})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(mult), result);
}

TEST(VisitorMultTest, Nine_times_Seven_times_Eleven) {
    Base* op1 = new Op(9);
    Base* op2 = new Op(7);
    Base* op3 = new Op(11);
    Base* mult = new Mult(op2, op3);
    Base* mult2 = new Mult(op1, mult);
    std::string result = "${({9}\\cdot{({7}\\cdot{11})})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(mult2), result);
}

TEST(VisitorMultTest, Three_times_Five_times_Seven_times_Eleven) {
    Base* op1 = new Op(3);
    Base* op2 = new Op(5);
    Base* op3 = new Op(7);
    Base* op4 = new Op(11);
    Base* mult = new Mult(op1, op2);
    Base* mult2 = new Mult(op3, op4);
    Base* mult3 = new Mult(mult, mult2);
    std::string result = "${({({3}\\cdot{5})}\\cdot{({7}\\cdot{11})})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(mult3), result);
}

#endif //__MULTTEST_HPP__ 
