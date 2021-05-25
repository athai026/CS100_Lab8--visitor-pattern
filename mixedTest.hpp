#ifndef __MIXEDTEST_HPP__
#define __MIXEDTEST_HPP__

#include <string>
#include "gtest/gtest.h"
#include "VisitorLaTeX.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"

TEST(MixedTest, SubDiv) {
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* div = new Div(two, three);
    Base* sub = new Sub(one, div);
    std::string result = "${({1}-{\\frac{2}{3}})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(sub), result);
}

TEST(MixedTest, DivSub) {
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* sub = new Sub(two, three);
    Base* div = new Div(one, sub);
    std::string result = "${\\frac{1}{({2}-{3})}}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(div), result);
}

TEST(MixedTest, MultDiv) {
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* div = new Div(two, three);
    Base* mult = new Mult(one, div);
    std::string result = "${({1}\\cdot{\\frac{2}{3}})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(mult), result);
}

TEST(MixedTest, AddMult) {
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* mult = new Mult(two, three);
    Base* add = new Add(one, mult);
    std::string result = "${({1}+{({2}\\cdot{3})})}$";
    VisitorLaTeX v;
    EXPECT_EQ(v.PrintLaTeX(add), result);
}

#endif //__MIXEDTEST_HPP__
