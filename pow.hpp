#ifndef __POW_HPP__
#define __POW_HPP__

#include "op.hpp"
#include <cmath>

class Pow : public Base {
    public:
        Pow(Base* left, Base* right) : Base() {
            l_value = left->evaluate();
            r_value = right->evaluate();
            l_string = left->stringify();
            r_string = right->stringify();
	    l_child = left;
	    r_child = right;
        }
        virtual double evaluate() {
        	product = 1.0;

    		if (r_value == 0) {
        		return product;
    		}
   		else if (l_value == 0) {
        		if (r_value <= 0) {
            			throw "Undefined error";
        		}	
        		else {
            			product = 0.0;
            			return product;
        		}
    		}
    		else {
        		for (int i = 0; i < fabs(r_value); ++i) {
            			product *= l_value;
        		}

        		if (r_value < 0) {
            			return (1 / product);
        		}
        		else {
            			return product;
        		}
    		}
	}
        virtual std::string stringify() {
            return ("(" + l_string + "**" + r_string + ")");
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
                return l_child;
            }
            else {
                return r_child;
            }
        }

        void accept(Visitor* visitor, int index) {
            if (index == 0) {
                visitor->visit_pow_begin(this);
            }
            else if (index == 1) {
                visitor->visit_pow_middle(this);
            }
            else if (index == 2) {
                visitor->visit_pow_end(this);
            }
        }
    private:
        double l_value, r_value, product;
        std::string l_string, r_string;
        Base* l_child;
        Base* r_child;
};

#endif //__POW_HPP__
