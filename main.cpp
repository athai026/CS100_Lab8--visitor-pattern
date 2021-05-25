#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "VisitorLaTeX.hpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    //std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    
    std::cout << "Expected: ${({({3}+{({7}\\cdot{4})})}-{2})}$" << std::endl;
    VisitorLaTeX v;
    std::cout << "Got:      " << v.PrintLaTeX(minus) << std::endl;

    delete minus;
    delete add;
    delete mult;
    delete two;
    delete three;
    delete four;
    delete seven;
    return 0;
}
