#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "op.hpp"

class Div : public Base {
    public:
        Base* l_child;
        Base* r_child;
        Div(Base* left, Base* right) : Base() {
            l_value = left->evaluate();
            r_value = right->evaluate();
            l_string = left->stringify();
            r_string = right->stringify();
            l_child = left;
            r_child = right;
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

        virtual int number_of_children() {
            int num_child = 0;
            if (l_child != nullptr) {
                ++num_child;
            }
            if (r_child != nullptr) {
                ++num_child;
            }
            return num_child;
        }
        virtual Base* get_child(int i) {
            if (i  == 0) {
                return l_child;
            }
            else if (i == 1) {
                return r_child;
            }
            else {
                return nullptr;
            }
        }

        void accept(Visitor* visitor, int index) {
            if (index == 0) {
                visitor->visit_div_begin(this);
            }
            else if (index == 1) {
                visitor->visit_div_middle(this);
            }
            else if (index == 2) {
                visitor->visit_div_end(this);
            }
            else {
                std::cout << "Error invalid index " << index << std::endl;
            }
        }

    private: 
        double l_value, r_value, quotient;
        std::string l_string, r_string;
        Base* left;
        Base* right;
};

#endif //__DIV_HPP__
