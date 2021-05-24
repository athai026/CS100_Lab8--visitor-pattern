#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "op.hpp"

class Add : public Base {
    public:
        Add(Base* left, Base* right) : Base() {
            l_value = left->evaluate();
            r_value = right->evaluate();
            l_string = left->stringify();
            r_string = right->stringify();
        }
        virtual double evaluate() {
            sum = l_value + r_value;
            return sum;
        }
        virtual std::string stringify() {
            return ("(" + l_string + "+" + r_string + ")");
        }

    private:
        double l_value, r_value,sum;
        std::string l_string, r_string;
        Base* left;
        Base* right;
};

#endif //__ADD_HPP__
