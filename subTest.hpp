#ifndef __SUBTEST_HPP__
#define __SUBTEST_HPP__

#include <string>
#include "gtest/gtest.h"
#include "VisitorLaTeX.hpp"
#include "iterator.hpp"
#include "iterator.cpp"
#include "sub.hpp"
#include "op.hpp"

TEST(VisitorSubTest, Ten_minus_Five) {
    Base* op1 = new Op(10);
    Base* op2 = new Op(5);
    Base* sub = new Sub(op1, op2);
    std::string result = "${({10}-{5})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(sub), result);
}

TEST(VisitorSubTest, Six_minus_Nine) {
    Base* op1 = new Op(6);
    Base* op2 = new Op(9);
    Base* sub = new Sub(op1, op2);
    std::string result = "${({6}-{9})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(sub), result);
}

TEST(VisitorSubTest, Nine_minus_Seven_minus_Eleven) {
    Base* op1 = new Op(9);
    Base* op2 = new Op(7);
    Base* op3 = new Op(11);
    Base* sub = new Sub(op2, op3);
    Base* sub2 = new Sub(op1, sub);
    std::string result = "${({9}-{({7}-{11})})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(sub2), result);
}

TEST(VisitorSubTest, Three_minus_Five_minus_Seven_minus_Eleven) {
    Base* op1 = new Op(3);
    Base* op2 = new Op(5);
    Base* op3 = new Op(7);
    Base* op4 = new Op(11);
    Base* sub = new Sub(op1, op2);
    Base* sub2 = new Sub(op3, op4);
    Base* sub3 = new Sub(sub, sub2);
    std::string result = "${({({3}-{5})}-{({7}-{11})})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(sub3), result);
}

#endif //__SUBTEST_HPP__ 
