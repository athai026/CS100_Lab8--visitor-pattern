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
	virtual int number_of_children() {
            if ( left != nullptr && right != nullptr) {
                return 2;
            }
            else {
                return 0;
            }
        }
        virtual Base* get_child(int i) {
            if (i  = 0) {
                return left;
            }
            else {
                return right;
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
        Base* left;
        Base* right;
};

#endif //__MULT_HPP__
