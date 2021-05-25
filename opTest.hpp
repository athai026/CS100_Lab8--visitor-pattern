#ifndef __OPTEST_HPP__
#define __OPTEST_HPP__

#include <string>
#include "gtest/gtest.h"
#include "VisitorLaTeX.hpp"
#include "iterator.cpp"
#include "op.hpp"

TEST(VisitorOpTest, One) {
    Base* op1 = new Op(1);
    std::string result = "${1}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(op1), result);
}

#endif //__OPTEST_HPP__
