#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "op.hpp"

class Mult : public Base {
    public:
        Mult(Base* left, Base* right) : Base() {
            l_value = left->evaluate();
            r_value = right->evaluate();
            l_string = left->stringify();
            r_string = right->stringify();
        }
        virtual double evaluate() {
            product = l_value * r_value;
            return product;
        }
        virtual std::string stringify() {
            return ("(" + l_string + "*" + r_string + ")");
        }

    private:
        double l_value, r_value, product;
        std::string l_string, r_string;
        Base* left;
        Base* right;
};

#endif //__MULT_HPP__
