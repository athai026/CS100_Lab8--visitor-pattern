#ifndef __ADDTEST_HPP__
#define __ADDTEST_HPP__

#include <string>
#include "gtest/gtest.h"
#include "VisitorLaTeX.hpp"
#include "iterator.cpp"
#include "add.hpp"
#include "op.hpp"

TEST(VisitorAddTest, Ten_plus_Five) {
    Base* op1 = new Op(10);
    Base* op2 = new Op(5);
    Base* add = new Add(op1, op2);
    std::string result = "${({10}+{5})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(add), result);
}

TEST(VisitorAddTest, Six_plus_Nine) {
    Base* op1 = new Op(6);
    Base* op2 = new Op(9);
    Base* add = new Add(op1, op2);
    std::string result = "${({6}+{9})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(add), result);
}

TEST(VisitorAddTest, Nine_plus_Seven_plus_Eleven) {
    Base* op1 = new Op(9);
    Base* op2 = new Op(7);
    Base* op3 = new Op(11);
    Base* add = new Add(op2, op3);
    Base* add2 = new Add(op1, add);
    std::string result = "${({9}+{({7}+{11})})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(add2), result);
}

TEST(VisitorAddTest, Three_plus_Five_plus_Seven_plus_Eleven) {
    Base* op1 = new Op(3);
    Base* op2 = new Op(5);
    Base* op3 = new Op(7);
    Base* op4 = new Op(11);
    Base* add = new Add(op1, op2);
    Base* add2 = new Add(op3, op4);
    Base* add3 = new Add(add, add2);
    std::string result = "${({({3}+{5})}+{({7}+{11})})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(add3), result);
}

#endif //__ADDTEST_HPP__
