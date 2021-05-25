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

#endif //__SUBTEST_HPP__ 
