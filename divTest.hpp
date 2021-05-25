#ifndef __DIVTEST_HPP__
#define __DIVTEST_HPP__

#include <string>
#include "gtest/gtest.h"
#include "VisitorLaTeX.hpp"
#include "div.hpp"
#include "op.hpp"

TEST(VisitorDivTest, Ten_div_Five) {
    Base* op1 = new Op(10);
    Base* op2 = new Op(5);
    Base* div = new Div(op1, op2);
    std::string result = "${\\frac{10}{5}}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(div), result);
}

TEST(VisitorDivTest, Two_div_Eleven) {
    Base* op1 = new Op(2);
    Base* op2 = new Op(11);
    Base* div = new Div(op1, op2);
    std::string result = "${\\frac{2}{11}}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(div), result);
}

TEST(VisitorDivTest, One_div_Two_div_Three) {
    Base* op1 = new Op(1);
    Base* op2 = new Op(2);
    Base* op3 = new Op(3);
    Base* div = new Div(op1, op2);
    Base* div2 = new Div(div, op3);
    std::string result = "${\\frac{\\frac{1}{2}}{3}}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(div2), result);
}

TEST(VisitorDivTest, One_div_Two_div_Three_div_Four) {
    Base* op1 = new Op(1);
    Base* op2 = new Op(2);
    Base* op3 = new Op(3);
    Base* op4 = new Op(4);
    Base* div = new Div(op1, op2);
    Base* div2 = new Div(op3, op4);
    Base* div3 = new Div(div, div2);
    std::string result = "${\\frac{\\frac{1}{2}}{\\frac{3}{4}}}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(div3), result);
}


#endif //__DIVTEST_HPP__
