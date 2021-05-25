#ifndef __OPTEST_HPP__
#define __OPTEST_HPP__

#include <string>
#include "gtest/gtest.h"
#include "VisitorLaTeX.hpp"
#include "op.hpp"

TEST(VisitorOpTest, One) {
    Base* op1 = new Op(1);
    std::string result = "${1}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(op1), result);
}

TEST(VisitorOpTest, negOne) {
    Base* op1 = new Op(-1);
    std::string result = "${-1}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(op1), result);
}

TEST(VisitorOpTest, Ten) {
    Base* op1 = new Op(10);
    std::string result = "${10}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(op1), result);
}

TEST(VisitorOpTest, negTen) {
    Base* op1 = new Op(-10);
    std::string result = "${-10}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(op1), result);
}

#endif //__OPTEST_HPP__
