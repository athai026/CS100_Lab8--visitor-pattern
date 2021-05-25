#ifndef __POWTEST_HPP__
#define __POWTEST_HPP__

#include <string>
#include "gtest/gtest.h"
#include "VisitorLaTeX.hpp"
#include "iterator.cpp"
#include "pow.hpp"
#include "op.hpp"

TEST(VisitorPowTest, Ten_power_Five) {
    Base* op1 = new Op(10);
    Base* op2 = new Op(5);
    Base* pow = new Pow(op1, op2);
    std::string result = "${({10}^{5})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(pow), result);
}

TEST(VisitorPowTest, Six_power_Nine) {
    Base* op1 = new Op(6);
    Base* op2 = new Op(9);
    Base* pow = new Pow(op1, op2);
    std::string result = "${({6}^{9})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(pow), result);
}

TEST(VisitorPowTest, Six_power_Zero) {
    Base* op1 = new Op(6);
    Base* op2 = new Op(0);
    Base* pow = new Pow(op1, op2);
    std::string result = "${({6}^{0})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(pow), result);
}

TEST(VisitorPowTest, Zero_power_Nine) {
    Base* op1 = new Op(0);
    Base* op2 = new Op(9);
    Base* pow = new Pow(op1, op2);
    std::string result = "${({0}^{9})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(pow), result);
}

#endif //__POWTEST_HPP__ 
