#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "op.hpp"

class Div : public Base {
    public:
        Div(Base* left, Base* right) : Base() {
            l_value = left->evaluate();
            r_value = right->evaluate();
            l_string = left->stringify();
            r_string = right->stringify();
        }
        virtual double evaluate() {
            if (r_value == 0) {
                throw "Cannot divide by zero";
            }
            else {
                quotient = l_value / r_value;
                return quotient;
            }
        }
        virtual std::string stringify() {
            return ("(" + l_string + "/" + r_string + ")");
        }

    private: 
        double l_value, r_value, quotient;
        std::string l_string, r_string;
        Base* left;
        Base* right;
};

#endif //__DIV_HPP__
