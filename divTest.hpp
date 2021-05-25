#ifndef __DIVTEST_HPP__
#define __DIVTEST_HPP__

#include <string>
#include "gtest/gtest.h"
#include "VisitorLaTeX.hpp"
#include "iterator.cpp"
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

#endif //__DIVTEST_HPP__
