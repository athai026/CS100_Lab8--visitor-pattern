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
	    l_child = left;
	    r_child = right;
        }
        virtual double evaluate() {
            product = l_value * r_value;
            return product;
        }
        virtual std::string stringify() {
            return ("(" + l_string + "*" + r_string + ")");
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
            if (i == 0) {
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
                visitor->visit_mult_begin(this);
            }
            else if (index == 1) {
                visitor->visit_mult_middle(this);
            }
            else if (index == 2) {
                visitor->visit_mult_end(this);
            }
        }
    private:
        double l_value, r_value, product;
        std::string l_string, r_string;
        Base* l_child;
        Base* r_child;
};

#endif //__MULT_HPP__
